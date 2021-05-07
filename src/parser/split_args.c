/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:35:50 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 13:46:08 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_struct(t_data **data)
{
	(*data)->cmd = 0;
	(*data)->have_pipe = 0;
	(*data)->args = NULL;
	(*data)->redirects = NULL;
}

int	get_pipe(char *line)
{
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (*line == '|')
		{
			ft_memset(line, ' ', 1);
			return (1);
		}
		line++;
	}
	return (0);
}

int	split_arguments(t_list **list, char **cmd_arr, char **env[])
{
	t_data	*data;
	t_list	*args_holder;
	char	*parsed_cmd;

	while (*cmd_arr)
	{
		if (is_empty(*cmd_arr))
			break ;
		data = (t_data *)malloc(sizeof(t_data));
		init_struct(&data);
		args_holder = NULL;
		parsed_cmd = pre_parse(*cmd_arr, *env, pre_parse_size(*cmd_arr, *env));
		data->have_pipe = get_pipe(parsed_cmd);
		data->redirects = get_redirects(parsed_cmd);
		delete_redirection(parsed_cmd);
		if (validate_redirects(data, parsed_cmd, env) < 0)
			return (-1);
		parse_get_cmd(parsed_cmd, data);
		parse_get_args(parsed_cmd, &args_holder, &data);
		ft_lstadd_back(list, ft_lstnew(data));
		free(parsed_cmd);
		cmd_arr++;
	}
	return (0);
}
