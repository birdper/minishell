/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:57:00 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/27 12:44:49 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_braces(char **line)
{
	if (**line == '(' || **line == ')' || **line == '[' || **line == ']'
		|| **line == '`' || **line == '{' || **line == '}')
	{
		ft_putstr_fd("minishell: syntax error: unexpected token `", 2);
		ft_putchar_fd(**line, 2);
		ft_putendl_fd("\'", 2);
		return (-1);
	}
	return (0);
}

static int	check_ecranization(char **line)
{
	if (**line == '\\')
	{
		if (*(*line + 1) == '\0')
		{
			ft_putendl_fd("minishell: syntax error: multiline command", 2);
			return (-1);
		}
		*line += 2;
		return (1);
	}
	return (0);
}

static int	check_single_quotes(char **line)
{
	if (**line == '\'')
	{
		(*line)++;
		while (**line != '\'')
		{
			if (**line == '\0')
			{
				ft_putendl_fd("minishell: syntax error: multiline command", 2);
				return (-1);
			}
			(*line)++;
		}
		(*line)++;
		return (1);
	}
	return (0);
}

static int	check_quotes(char **line)
{
	if (**line == '\"')
	{
		(*line)++;
		while (**line != '\"')
		{
			if (**line == '\\')
			{
				*line += 2;
				continue ;
			}
			if (**line == '\0')
			{
				ft_putendl_fd("minishell: syntax error: multiline command", 2);
				return (-1);
			}
			(*line)++;
		}
		(*line)++;
		return (1);
	}
	return (0);
}

int	check_symbol(char **line)
{
	int	res;

	res = check_braces(line);
	if (res)
		return (res);
	res = check_ecranization(line);
	if (res)
		return (res);
	res = check_single_quotes(line);
	if (res)
		return (res);
	res = check_quotes(line);
	if (res)
		return (res);
	return (0);
}
