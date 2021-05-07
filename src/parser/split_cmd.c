/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:03:23 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 13:40:25 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	cmd_count(char *line)
{
	int	count;

	count = 1;
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (*line == ';' || *line == '\n')
			count++;
		line++;
	}
	return (count);
}

static char	*split_line(char *line, char **new)
{
	char	*tmp;

	tmp = line;
	while (*tmp)
	{
		if (skip_spec_symbols(&tmp))
			continue ;
		if (*tmp == ';' || *tmp == '\n')
		{
			*new = ft_substr(line, 0, tmp - line);
			line = tmp + 1;
			break ;
		}
		tmp++;
	}
	return (line);
}

char	**split_cmd(char *line)
{
	char	**new;
	int		size;
	int		i;

	i = 0;
	size = cmd_count(line);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	while (i < size)
	{
		line = split_line(line, &new[i]);
		i++;
	}
	if (size > 0)
		new[size - 1] = ft_strdup(line);
	return (new);
}
