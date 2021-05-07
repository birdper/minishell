/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:11:46 by nbirdper          #+#    #+#             */
/*   Updated: 2021/05/01 00:11:49 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	parent_close_pipe(t_pipeline *pipeline, uint32_t *num_cmd)
{
	if (*num_cmd > 0)
		close(pipeline->ends_prev_pipe[*num_cmd - 1]);
	pipeline->ends_prev_pipe[*num_cmd] = dup(pipeline->pipe_fds[READ_END]);
	close(pipeline->pipe_fds[WRITE_END]);
	close(pipeline->pipe_fds[READ_END]);
	(*num_cmd)++;
}

static void	swap_io(t_data *command, uint32_t num_cmd, t_pipeline *pipeline)
{
	close(pipeline->pipe_fds[READ_END]);
	if (num_cmd > 0)
	{
		dup2close(pipeline->ends_prev_pipe[num_cmd - 1], STDIN_FILENO);
		if (command->have_pipe == 0)
			close(pipeline->pipe_fds[WRITE_END]);
		else
			dup2close(pipeline->pipe_fds[WRITE_END], STDOUT_FILENO);
	}
	else
		dup2close(pipeline->pipe_fds[WRITE_END], STDOUT_FILENO);
}

static void	child_run(t_data *command, uint32_t num_cmd, t_pipeline *pipeline,
						char ***envp)
{
	int		status;

	swap_io(command, num_cmd, pipeline);
	if (command->redirects)
	{
		if (find_redirections(command->redirects, &pipeline->redir_fds))
			exit(EXIT_FAILURE);
		set_redirections(&pipeline->redir_fds);
	}
	if (command->cmd == e_empty)
		status = outer_exec(command->args[0], command->args, *envp);
	else
		status = builtins(command->cmd, (const char **)command->args, envp);
	exit(status);
}

static int	pipelining(t_list *list, t_pipeline *pipeline, char **envp)
{
	t_data		*cmd;
	pid_t		pid;
	uint32_t	num_cmd;

	num_cmd = 0;
	while (num_cmd < pipeline->number_cmd)
	{
		cmd = list->content;
		pipe(pipeline->pipe_fds);
		errno = 0;
		pid = fork();
		if (pid == CHILD)
			child_run(cmd, num_cmd, pipeline, &envp);
		else if (pid < 0)
		{
			print_err("minishell", cmd->args[0], NULL, strerror(errno));
			return (-1);
		}
		else
		{
			parent_close_pipe(pipeline, &num_cmd);
			list = list->next;
		}
	}
	return (0);
}

int	run_pipeline(t_list *list_commands, char **envp, int size)
{
	t_pipeline	pipeline;
	int			num_cmd;
	int			status;
	int			stt;

	status = 0;
	pipeline.number_cmd = size;
	pipeline.ends_prev_pipe = (int *)malloc(sizeof(int) * size - 1);
	pipelining(list_commands, &pipeline, envp);
	free(pipeline.ends_prev_pipe);
	num_cmd = 0;
	while (num_cmd++ < size)
	{
		wait(&stt);
		if (WIFSIGNALED(stt))
			status = WTERMSIG(stt) + 128;
		else if (WIFEXITED(stt))
			status = WEXITSTATUS(stt);
	}
	return (status);
}
