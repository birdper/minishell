/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:05:54 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 15:19:44 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_flag_n(char *str)
{
	if (*str == '-' && *(str + 1) == 'n')
	{
		str++;
		while (*str == 'n')
			str++;
		if (*str == '\0')
			return (1);
	}
	return (0);
}

int	is_empty(char *str)
{
	while (*str == ' ')
		str++;
	if (ft_strlen(str) == 0)
		return (1);
	return (0);
}

void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

int	brake_end_line(char **line)
{
	if (**line == '\0')
		return (1);
	(*line)++;
	while (**line == ' ')
		(*line)++;
	if (**line == '\0')
		return (1);
	return (0);
}
