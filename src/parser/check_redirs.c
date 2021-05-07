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

static int	check_ambigous(char *file, char **env)
{
    char    *tmp;
    int     len;

    tmp = file;
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
        free(file);
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
	while (*str && ft_strchr(" ><|;", *str) == 0)
	{
		ft_strncat(filename, str, ++i, 1);
		str++;
	}
	return (filename);
}

int	check_redirs(char *line, char **env)
{
	char	*file;

	if (*line == '>' || *line == '<')
	{
		if (*line == '>' && *(line + 1) == '>')
			line++;
		line++;
		skip_spaces(&line);
		file = pre_parse_filename(line);
		if (check_redir_len(file))
			return (1);
		if (check_ambigous(file, env))
			return (1);
		free(file);
	}
	return (0);
}
