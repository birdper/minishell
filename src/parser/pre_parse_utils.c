/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:25:28 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:05:20 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	pre_parse_copy_ecranization(char **line, char *str, int *i)
{
	if (**line == '\\')
	{
		*i += 2;
		ft_strncat(str, *line, *i, 2);
		*line += 2;
		return (1);
	}
	return (0);
}

int	pre_parse_copy_single_quotes(char **line, char *str, int *i)
{
	int	k;

	if (**line == '\'')
	{
		k = 1;
		while ((*line)[k] && (*line)[k] != '\'')
			k++;
		k++;
		*i += k;
		ft_strncat(str, *line, *i, k);
		*line += k;
		return (1);
	}
	return (0);
}

int	pre_parse_copy_env(char **line, char *str, char **env, int *i)
{
	int	len;

	if (**line == '$')
	{
		if (skip_valid_env(line, str))
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

int	pre_parse_copy_quotes(char **line, char *str, char **env, int *i)
{
	if (**line == '\"')
	{
		ft_strncat(str, *line, ++(*i), 1);
		(*line)++;
		while (**line && **line != '\"')
		{
			if (pre_parse_copy_ecranization(line, str, i))
				continue ;
			if (pre_parse_copy_env_quotes(line, str, env, i))
				continue ;
			ft_strncat(str, *line, ++(*i), 1);
			(*line)++;
		}
		ft_strncat(str, *line, ++(*i), 1);
		(*line)++;
		return (1);
	}
	return (0);
}

int	pre_parce_skip_env(char **line, int *count, char **env)
{
	if (**line == '$')
	{
		(*line)++;
		*count += pre_parse_env_size(*line, env);
		*count -= env_name_size(*line) + 1;
		*line += env_name_size(*line);
		return (1);
	}
	return (0);
}
