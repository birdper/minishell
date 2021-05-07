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

int	validate_redirs(char *line, char **env)
{
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (check_redirs(line, env))
			return (-1);
		line++;
	}
	return (0);
}

int	pre_parse_validate(char *line, char **env)
{
	if (validate_spec_symbols(line))
		return (-1);
	if (validate_cmd(line))
		return (-1);
	if (validate_redirs(line, env))
		return (-1);
	return (0);
}
