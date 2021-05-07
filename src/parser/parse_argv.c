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

int	add_spec_symbol(char **line, char *str, int *i)
{
	if (add_ecranization(line, str, i))
		return (1);
	if (add_single_quotes(line, str, i))
		return (1);
	if (add_double_quotes(line, str, i))
		return (1);
	return (0);
}

int	get_new_argument(char *line, char *str, t_list **args_holder)
{
	if (*line == ' ' || *line == '<' || *line == '>'
		|| *line == '|' || *line == '\0')
	{
		ft_lstadd_back(args_holder, ft_lstnew(str));
		return (1);
	}
	return (0);
}

static int	parse_set_args(t_data **data, t_list *args_holder)
{
	int	i;

	i = 0;
	while (args_holder)
	{
		if ((*data)->cmd == 1 && i > 0 && is_flag_n(args_holder->content))
		{
			free(args_holder->content);
			(*data)->args[i] = ft_strdup("-n");
		}
		else
			(*data)->args[i] = args_holder->content;
		args_holder = args_holder->next;
		i++;
	}
	(*data)->args[i] = NULL;
	return (0);
}

static int	get_args(char *line, t_list **args_holder)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)ft_calloc(ft_strlen(line) + 1, 1);
	skip_spaces(&line);
	while (1)
	{
		if (add_spec_symbol(&line, str, &i))
			continue ;
		if (get_new_argument(line, str, args_holder) == 1)
		{
			if (brake_end_line(&line))
				break ;
			i = 1;
			str = (char *)ft_calloc(ft_strlen(line) + 1, 1);
			continue ;
		}
		ft_strncat(str, line, ++i, 1);
		line++;
	}
	return (0);
}

int	parse_get_args(char *line, t_list **args_holder, t_data **data)
{
	int	len;

	get_args(line, args_holder);
	len = ft_lstsize(*args_holder);
	(*data)->args = (char **)malloc(sizeof(char *) * (len + 1));
	(*data)->args[len] = NULL;
	parse_set_args(data, *args_holder);
	ft_lstclear_no_content(args_holder);
	return (0);
}
