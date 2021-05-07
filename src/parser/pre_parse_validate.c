/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:01:01 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 21:37:13 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	validate_redirects(t_data *data, char *parsed_cmd, char **envp[])
{
	t_redirect	*rd;
	t_list		*redirects;

	redirects = data->redirects;
	while (redirects)
	{
		rd = redirects->content;
		if (ft_strlen(rd->rd_file) == 0)
		{
			ft_putendl_fd("minishell: ambiguous redirect", 2);
			set_value_by_key("?", "1", *envp);
			clear_data(data);
			free(data);
			free(parsed_cmd);
			return (-1);
		}
		redirects = redirects->next;
	}
	return (0);
}

static int	validate_spec_symbols(char *line)
{
	int	res;

	while (*line)
	{
		res = check_symbol(&line);
		if (res < 0)
			return (-1);
		else if (res == 1)
			continue ;
		line++;
	}
	return (0);
}

int	check_redirs(char *line)
{
	char	*file;

	if (*line == '>' || *line == '<')
	{
		if (*line == '>' && *(line + 1) == '>')
			line++;
		line++;
		skip_spaces(&line);
		file = get_file_name(line);
		if (ft_strlen(file) == 0)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			if (line[ft_strlen(file)] == '\0')
				ft_putendl_fd("newline'", 2);
			else
			{
				ft_putchar_fd(line[ft_strlen(file)], 2);
				ft_putendl_fd("'", 2);
			}
			free(file);
			return (1);
		}
		free(file);
	}
	return (0);
}

int	validate_redirs(char *line)
{
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (check_redirs(line))
			return (-1);
		line++;
	}
	return (0);
}

int	pre_parse_validate(char *line)
{
	if (validate_spec_symbols(line))
		return (-1);
	if (validate_cmd(line))
		return (-1);
	if (validate_redirs(line))
		return (-1);
	return (0);
}
