/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:04:04 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:04:06 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

enum e_cmd	comparator(char *command)
{
	if (ft_strncmp(command, "echo", 5) == 0)
		return (e_echo);
	if (ft_strncmp(command, "cd", 3) == 0)
		return (e_cd);
	if (ft_strncmp(command, "pwd", 4) == 0)
		return (e_pwd);
	if (ft_strncmp(command, "export", 7) == 0)
		return (e_export);
	if (ft_strncmp(command, "unset", 6) == 0)
		return (e_unset);
	if (ft_strncmp(command, "env", 4) == 0)
		return (e_env);
	if (ft_strncmp(command, "exit", 5) == 0)
		return (e_exit);
	return (e_empty);
}

enum e_cmd	get_cmd(char *line, char *str)
{
	int		i;

	i = 1;
	while (*line)
	{
		if (add_spec_symbol(&line, str, &i))
			continue ;
		if (*line == ' ')
		{
			line++;
			return (comparator(str));
		}	
		if (*line == '>' || *line == '<' || *line == '|')
			return (comparator(str));
		ft_strncat(str, line, ++i, 1);
		line++;
	}
	return (comparator(str));
}

int	parse_get_cmd(char *line, t_data *data)
{
	char	*str;
	int		len;

	while (*line == ' ')
		line++;
	len = ft_strlen(line);
	str = (char *)ft_calloc(len + 1, 1);
	data->cmd = get_cmd(line, str);
	free(str);
	return (0);
}

char	**get_cmd_arr(char *line, char **envp[])
{
	char	**cmd_arr;

	delete_comments(line);
	if (pre_parse_validate(line, *envp))
	{
		set_value_by_key("?", "258", *envp);
		free(line);
		return (0);
	}
	cmd_arr = split_cmd(line);
	free(line);
	return (cmd_arr);
}
