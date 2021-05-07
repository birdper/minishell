#include "executor.h"

static void	restore_io(const t_data *command, t_redir_fds *redir_fds)
{
	if (command->redirects)
	{
		dup2close(redir_fds->dup_in, STDIN_FILENO);
		dup2close(redir_fds->dup_out, STDOUT_FILENO);
	}
}

static int	check_redirs(t_data *command, t_redir_fds *redir_fds)
{
	redir_fds->dup_in = dup(STDIN_FILENO);
	redir_fds->dup_out = dup(STDOUT_FILENO);
	if (command->redirects)
	{
		if (find_redirections(command->redirects, redir_fds))
		{
			close(redir_fds->dup_in);
			close(redir_fds->dup_out);
			return (1);
		}
		set_redirections(redir_fds);
	}
	return (0);
}

static int32_t	fork_exec(char *filename, char **args, char **envp)
{
	pid_t	pid;
	int		status;

	errno = 0;
	pid = fork();
	if (pid == CHILD)
		outer_exec(filename, args, envp);
	if (pid < 0)
	{
		status = -1;
		print_err("minishell", args[0], NULL, strerror(errno));
	}
	else
	{
		wait(&status);
		if (WIFSIGNALED(status))
			status = WTERMSIG(status) + 128;
		else if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}

int	simple_command(t_data *command, char **envp[])
{
	t_redir_fds		redir_fds;
	int				status;

	if (check_redirs(command, &redir_fds))
		return (1);
	if (command->cmd == e_empty)
		status = fork_exec(command->args[0], command->args, *envp);
	else
		status = builtins(command->cmd, (const char **)command->args, envp);
	restore_io(command, &redir_fds);
	return (status);
}
