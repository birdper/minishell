/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:56:09 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/29 15:22:53 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	add_ecranization(char **line, char *str, int *i)
{
	if (**line == '\\' && *(*line + 1))
	{
		(*line)++;
		ft_strncat(str, *line, ++(*i), 1);
		(*line)++;
		if (**line == '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	add_single_quotes(char **line, char *str, int *i)
{
	if (**line == '\'')
	{
		(*line)++;
		while (**line && **line != '\'')
		{
			ft_strncat(str, *line, ++(*i), 1);
			(*line)++;
		}
		(*line)++;
		if (**line == '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	add_double_quotes(char **line, char *str, int *i)
{
	if (**line == '\"')
	{
		(*line)++;
		while (**line && **line != '\"')
		{
			if (**line == '\\' && (*(*line + 1) == '$'
					|| *(*line + 1) == '"' || *(*line + 1) == '\\'))
			{
				(*line)++;
				ft_strncat(str, *line, ++(*i), 1);
				(*line)++;
				continue ;
			}
			ft_strncat(str, *line, ++(*i), 1);
			(*line)++;
		}
		(*line)++;
		if (**line == '\0')
			return (0);
		return (1);
	}
	return (0);
}
