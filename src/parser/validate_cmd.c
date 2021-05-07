/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:12:06 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/27 12:43:46 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_cmd_end(char *line)
{
	if (*line == '|' || *line == ';')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putchar_fd(*line, 2);
		ft_putendl_fd("\'", 2);
		return (-1);
	}
	return (0);
}

static int	check_cmd_multiline(char *line)
{
	if (*line == '|')
	{
		if (line[spaces_count(line + 1) + 1] == '\0')
		{
			ft_putendl_fd("minishell: syntax error: multiline command", 2);
			return (-1);
		}
	}
	return (0);
}

int	validate_cmd(char *line)
{
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (check_cmd_end(line) < 0)
			return (-1);
		while (*line && (*line != '|' && *line != ';'))
		{
			if (skip_spec_symbols(&line))
				continue ;
			line++;
		}
		if (check_cmd_multiline(line) < 0)
			return (-1);
		if (*line == '|' || *line == ';')
			line++;
	}
	return (0);
}
