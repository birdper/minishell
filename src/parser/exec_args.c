/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:46:25 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 16:47:47 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**read_cmd_args(int argc, char **argv)
{
	char	**cmd_arr;
	int		i;

	cmd_arr = (char **)malloc(sizeof(char *) * argc);
	i = 0;
	while (i < argc - 1)
	{
		cmd_arr[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	cmd_arr[i] = NULL;
	return (cmd_arr);
}

void	exec_args(t_list **list, int argc, char *argv[], char **envp[])
{
	char	**cmd_arr;
	int		status;

	cmd_arr = read_cmd_args(argc, argv);
	status = cmd_loop(list, cmd_arr, envp);
	if (cmd_arr)
		ft_free_2arr(cmd_arr);
	exit(status);
}
