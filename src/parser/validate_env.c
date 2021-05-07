/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:28:17 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 01:01:43 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_printable_env(char c)
{
	if (c == 32 || c == 37 || c == 43 || c == 44 || c == 46 || c == 47
		|| c == 58 || c == 61 || c == 92 || c == 94 || c == 126 || c == 0)
		return (1);
	return (0);
}

int	is_valid_env(char *line)
{
	if (is_printable_env(*line))
		return (2);
	if (*line == '\'' || *line == '\"')
		return (3);
	if (!ft_isalpha(*line) && *line != '_' && *line != '?')
		return (1);
	return (0);
}

int	skip_valid_env(char **line, char *str)
{
	if (is_valid_env(*line + 1) == 2)
	{
		ft_strncat(str, *line, ft_strlen(str) + 1 + 1, 1);
		(*line)++;
		return (1);
	}
	if (is_valid_env(*line + 1) == 3)
	{
		*line += 1;
		return (1);
	}
	if (is_valid_env(*line + 1) == 1)
	{
		*line += 2;
		return (1);
	}
	return (0);
}
