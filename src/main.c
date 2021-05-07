/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:11:09 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/01 20:57:24 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(void)
{
	write(1, "\e[1;35mminishell: \e[0m", 22);
}

static void	handle_signals(void)
{
	signal(SIGQUIT, sig_quit);
	signal(SIGINT, sig_interrupt);
}

int	cmd_loop(t_list **list, char **cmd_arr, char ***envp)
{
	int		status;

	if (cmd_arr == NULL)
		return (0);
	while (*cmd_arr)
	{
		if (parser(list, *cmd_arr, envp) < 0)
		{
			clear_cmd(list);
			cmd_arr++;
			continue ;
		}
		status = executor(*list, envp);
		clear_cmd(list);
		cmd_arr++;
	}
	return (status);
}

int	main(int argc, char *argv[], char *in_envp[])
{
	struct termios	term;
	t_2list			*history;
	t_list			*list;
	char			**envp;
	char			**cmd_arr;

	envp = init_subshell((const char **)argv, in_envp);
	handle_signals();
	history = NULL;
	tgetterm(&term);
	if (argc > 1)
		exec_args(&list, argc, argv, &envp);
	while (1)
	{
		print_prompt();
		cmd_arr = get_cmd_arr(create_cmd_line(&history, &envp, &term), &envp);
		cmd_loop(&list, cmd_arr, &envp);
		if (cmd_arr)
			ft_free_2arr(cmd_arr);
	}
	return (0);
}
