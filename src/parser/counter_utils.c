/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:28:58 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/01 13:32:05 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	spaces_count(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	ecranization_count(char *line)
{
	if (*line == '\\')
		return (2);
	return (0);
}

int	single_quotes_count(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\'')
	{
		i++;
		while (line[i] != '\'')
			i++;
		i++;
	}
	return (i);
}

int	quotes_count(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\"')
	{
		i++;
		while (line[i] != '\"')
		{
			if (line[i] == '\\')
			{
				i += 2;
				continue ;
			}
			i++;
		}
		i++;
	}
	return (i);
}

int	spec_symbol_count(char *line)
{
	int	i;

	i = 0;
	i += ecranization_count(line);
	if (i)
		return (i);
	i += single_quotes_count(line);
	if (i)
		return (i);
	i += quotes_count(line);
	return (i);
}
