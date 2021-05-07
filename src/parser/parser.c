/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:16:00 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:00:27 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	pipe_count(char *line)
{
	int	count;

	count = 1;
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (*line == '|')
			count++;
		line++;
	}
	return (count);
}

static char	*split_pipeline(char *line, char **new)
{
	char	*tmp;

	tmp = line;
	while (*tmp)
	{
		if (skip_spec_symbols(&tmp))
			continue ;
		if (*tmp == '|')
		{
			*new = ft_substr(line, 0, tmp - line + 1);
			line = tmp + 1;
			break ;
		}
		tmp++;
	}
	return (line);
}

char	**split_pipe(char *line)
{
	char	**new;
	int		size;
	int		i;

	i = 0;
	size = pipe_count(line);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	new[size] = NULL;
	while (i < size)
	{
		line = split_pipeline(line, &new[i]);
		i++;
	}
	new[size - 1] = ft_strdup(line);
	return (new);
}

void	delete_comments(char *line)
{
	while (*line)
	{
		if (skip_ecraniztion(&line))
			continue ;
		if (skip_single_quotes(&line))
			continue ;
		if (skip_quotes(&line))
			continue ;
		if (ft_memcmp(line, " #", 2) == 0)
			ft_memset(line, '\0', ft_strlen(line));
		line++;
	}
}

int	parser(t_list **list, char *line, char **env[])
{
	char	**pipe_arr;

	*list = NULL;
	pipe_arr = split_pipe(line);
	if (split_arguments(list, pipe_arr, env) < 0)
	{
		ft_free_2arr(pipe_arr);
		return (-1);
	}
	ft_free_2arr(pipe_arr);
	return (0);
}
