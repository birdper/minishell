/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:05:39 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:05:12 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_redir_len(char *file)
{
	if (ft_strlen(file) == 0)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (file[ft_strlen(file)] == '\0')
			ft_putendl_fd("newline'", 2);
		else
		{
			ft_putchar_fd(file[ft_strlen(file)], 2);
			ft_putendl_fd("'", 2);
		}
		free(file);
		return (1);
	}
	return (0);
}

static int	check_ambigous(char *filename, char **env)
{
	char	*tmp;
	int		len;

	tmp = filename;
	len = 0;
	while (*tmp == '$')
	{
		tmp++;
		len += pre_parse_env_size(tmp, env);
		tmp += env_name_size(tmp);
	}
	if (*tmp == 0 && len == 0)
	{
		ft_putendl_fd("minishell: ambiguous redirect", 2);
		free(filename);
		return (1);
	}
	return (0);
}

static char	*pre_parse_filename(char *str)
{
	char	*filename;
	int		i;

	i = 1;
	filename = (char *)ft_calloc(file_name_size(str) + 1, 1);
	while (*str && ft_strchr(" ><|;", *str) == NULL)
	{
		ft_strncat(filename, str, ++i, 1);
		str++;
	}
	return (filename);
}

int	check_redirs(char *line, char **env)
{
	char	*filename;

	if (*line == '>' || *line == '<')
	{
		if (*line == '>' && *(line + 1) == '>')
			line++;
		line++;
		skip_spaces(&line);
		filename = pre_parse_filename(line);
		if (check_redir_len(filename))
			return (1);
		if (check_ambigous(filename, env))
			return (1);
		free(filename);
	}
	return (0);
}
