/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:50:44 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/29 15:52:32 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	env_name_size(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '?')
		return (1);
	while (ft_isalpha(line[i]) || ft_isdigit(line[i]) || line[i] == '_')
		i++;
	return (i);
}

int	env_value_size(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == '\\' || *line == '\"' || *line == '\'' || *line == '>'
			|| *line == '<' || *line == '|')
			i++;
		i++;
		line++;
	}
	return (i);
}

size_t	env_value_cpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lim;
	size_t	srclen;

	srclen = ft_strlen((char *)src);
	lim = srclen;
	if (dstsize)
	{
		if (dstsize - 1 <= srclen)
			lim = dstsize - 1;
		i = 0;
		j = 0;
		while (i < lim)
		{
			if (src[i] == '\\' || src[i] == '\"' || src[i] == '>'
				|| src[i] == '<' || src[i] == '|')
				dst[j++] = '\\';
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (srclen);
}

int	copy_env(char *line, char **env, char *str)
{
	int	i;
	int	len;

	i = env_name_size(line);
	while (*env)
	{
		if (ft_strncmp(line, *env, i) == 0 && (*env)[i] == '=')
		{
			len = env_value_size(&(*env)[i + 1]);
			env_value_cpy(str, &(*env)[i + 1], len + 1);
			return (len);
		}
		env++;
	}
	return (0);
}

int	pre_parse_env_size(char *line, char **env)
{
	int	len;

	len = env_name_size(line);
	while (*env)
	{
		if (ft_strncmp(line, *env, len) == 0 && (*env)[len] == '=')
			return (env_value_size(&(*env)[len + 1]));
		env++;
	}
	return (0);
}
