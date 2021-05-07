/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:41:08 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/27 13:51:59 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	pre_parse_size(char *line, char **env)
{
	int	count;

	count = ft_strlen(line);
	while (*line)
	{
		if (skip_ecraniztion(&line))
			continue ;
		if (skip_single_quotes(&line))
			continue ;
		if (pre_parse_skip_quotes(&line, &count, env))
			continue ;
		if (pre_parce_skip_env(&line, &count, env))
			continue ;
		line++;
	}
	return (count);
}

char	*pre_parse(char *line, char **env, int size)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)ft_calloc(size + 1, 1);
	while (*line)
	{
		if (pre_parse_copy_ecranization(&line, str, &i))
			continue ;
		if (pre_parse_copy_single_quotes(&line, str, &i))
			continue ;
		if (pre_parse_copy_quotes(&line, str, env, &i))
			continue ;
		if (pre_parse_copy_env(&line, str, env, &i))
			continue ;
		ft_strncat(str, line, ++i, 1);
		line++;
	}
	return (str);
}
