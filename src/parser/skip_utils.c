/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:29:50 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/28 22:30:27 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	skip_ecraniztion(char **line)
{
	if (**line == '\\')
	{
		*line += 2;
		return (1);
	}
	return (0);
}

int	skip_single_quotes(char **line)
{
	if (**line == '\'')
	{
		(*line)++;
		while (**line && **line != '\'')
			(*line)++;
		(*line)++;
		return (1);
	}
	return (0);
}

int	skip_quotes(char **line)
{
	if (**line == '\"')
	{
		(*line)++;
		while (**line && **line != '\"')
		{
			if (skip_ecraniztion(line))
				continue ;
			(*line)++;
		}
		(*line)++;
		return (1);
	}
	return (0);
}

int	skip_spec_symbols(char **line)
{
	if (skip_ecraniztion(line))
		return (1);
	if (skip_single_quotes(line))
		return (1);
	if (skip_quotes(line))
		return (1);
	return (0);
}

int	pre_parse_skip_quotes(char **line, int *count, char **env)
{
	if (**line == '\"')
	{
		(*line)++;
		while (**line && **line != '\"')
		{
			if (skip_ecraniztion(line))
				continue ;
			if (pre_parce_skip_env(line, count, env))
				continue ;
			(*line)++;
		}
		(*line)++;
		return (1);
	}
	return (0);
}
