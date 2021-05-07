/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse_quotes_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 00:54:28 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 13:17:49 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_printable_env_quotes(char c)
{
	if (c == 32 || c == 37 || c == 43 || c == 44 || c == 46 || c == 47
		|| c == 58 || c == 61 || c == 92 || c == 94 || c == 126
		|| c == 34 || c == 39 || c == 0)
		return (1);
	return (0);
}

int	is_valid_env_quotes(char *line)
{
	if (is_printable_env_quotes(*line))
		return (2);
	if (*line == '\'' || *line == '\"')
		return (3);
	if (!ft_isalpha(*line) && *line != '_' && *line != '?')
		return (1);
	return (0);
}

int	skip_valid_env_quotes(char **line, char *str)
{
	if (is_valid_env_quotes(*line + 1) == 2)
	{
		ft_strncat(str, *line, ft_strlen(str) + 1 + 1, 1);
		(*line)++;
		return (1);
	}
	if (is_valid_env_quotes(*line + 1) == 3)
	{
		*line += 1;
		return (1);
	}
	if (is_valid_env_quotes(*line + 1) == 1)
	{
		*line += 2;
		return (1);
	}
	return (0);
}

int	pre_parse_copy_env_quotes(char **line, char *str, char **env, int *i)
{
	int	len;

	if (**line == '$')
	{
		if (skip_valid_env_quotes(line, str))
		{
			++(*i);
			return (1);
		}
		(*line)++;
		len = copy_env(*line, env, &str[ft_strlen(str)]);
		*i += len;
		if (**line == '?')
		{
			(*line)++;
			return (1);
		}
		while (ft_isalpha(**line) || ft_isdigit(**line) || **line == '_')
			(*line)++;
		return (1);
	}
	return (0);
}
