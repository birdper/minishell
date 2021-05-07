/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:21:58 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 21:43:39 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*delete_redirection(char *line)
{
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (*line == '>' || *line == '<')
		{
			if (*(line + 1) == '>')
			{
				ft_memset(line, ' ', 2);
				line++;
			}
			else
				ft_memset(line, ' ', 1);
			line++;
			skip_spaces(&line);
			ft_memset(line, ' ', file_name_size(line));
			line += file_name_size(line);
		}
		line++;
	}
	return (line);
}

enum e_redirect	get_redir_symbol(char *line)
{
	if (*line == '<')
		return (input);
	else if (*(line + 1) == '>')
		return (output_append);
	else
		return (output_rewrite);
}

int	file_name_size(char *str)
{
	int	len;

	len = 0;
	while (*str && *str != ' ' && *str != '|' && *str != '>' && *str != '<')
	{
		len += spec_symbol_count(str);
		if (skip_spec_symbols(&str))
			continue ;
		str++;
		len++;
	}
	return (len);
}

char	*get_file_name(char *str)
{
	char	*filename;
	int		i;

	i = 1;
	filename = (char *)ft_calloc(file_name_size(str) + 1, 1);
	while (*str && *str != ' ' && *str != '>' && *str != '<'
		&& *str != '|' && *str != ';')
	{
		if (add_spec_symbol(&str, filename, &i))
			continue ;
		if (*str == 0)
			break ;
		ft_strncat(filename, str, ++i, 1);
		str++;
	}
	return (filename);
}

t_list	*get_redirects(char *line)
{
	t_list		*redirects;
	t_redirect	*rd;

	redirects = NULL;
	while (*line)
	{
		if (skip_spec_symbols(&line))
			continue ;
		if (*line == '>' || *line == '<')
		{
			rd = (t_redirect *)malloc(sizeof(t_redirect));
			rd->rd_symbol = get_redir_symbol(line);
			rd->rd_file = NULL;
			if (*(line + 1) == '>')
				line++;
			line++;
			while (*line == ' ')
				line++;
			rd->rd_file = get_file_name(line);
			ft_lstadd_back(&redirects, ft_lstnew(rd));
			continue ;
		}
		line++;
	}
	return (redirects);
}
