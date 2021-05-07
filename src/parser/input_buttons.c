/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:13:33 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 15:20:48 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	left_right_button(char *buf)
{
	if (ft_strncmp(buf, "\e[D", 3) == 0)
		return (0);
	if (ft_strncmp(buf, "\e[C", 3) == 0)
		return (0);
	return (1);
}

int	backspace_button(t_reader *data, char *buf)
{
	if (*buf == 127)
	{
		if (data->i > 1)
		{
			if ((data->str)[data->i - 2] < 0)
				data->i -= 1;
			data->i -= 1;
			tputs(cursor_left, 1, tputchar);
			tputs(tigetstr("ed"), 1, tputchar);
			(data->str)[data->i - 1] = '\0';
		}
		return (1);
	}
	return (0);
}

int	up_button(t_2list **tmp_lst, t_reader *data, char *buf)
{
	if (ft_strncmp(buf, "\033[A", 3) == 0)
	{
		tputs(restore_cursor, 1, tputchar);
		tputs(tigetstr("ed"), 1, tputchar);
		if (*tmp_lst)
		{
			if (data->first == 0)
			{
				data->i = ft_strlen((*tmp_lst)->content) + 1;
				ft_strlcpy(data->str, (*tmp_lst)->content, data->i);
				write(1, (*tmp_lst)->content, data->i - 1);
				data->first = 1;
			}
			else
			{
				if ((*tmp_lst)->next != NULL)
					*tmp_lst = (*tmp_lst)->next;
				data->i = ft_strlen((*tmp_lst)->content) + 1;
				ft_strlcpy(data->str, (*tmp_lst)->content, data->i);
				write(1, (*tmp_lst)->content, data->i - 1);
			}
		}
		return (1);
	}
	return (0);
}

int	down_button(t_2list **tmp_lst, t_reader *data, char *buf)
{
	if (ft_strncmp(buf, "\e[B", 3) == 0)
	{
		tputs(restore_cursor, 1, tputchar);
		tputs(tigetstr("ed"), 1, tputchar);
		if (*tmp_lst)
		{
			if ((*tmp_lst)->prev != NULL)
			{
				*tmp_lst = (*tmp_lst)->prev;
				data->i = ft_strlen((*tmp_lst)->content) + 1;
				ft_strlcpy(data->str, (*tmp_lst)->content, data->i);
				write(1, (*tmp_lst)->content, data->i - 1);
			}
			else
			{
				data->first = 0;
				data->i = ft_strlen(data->backup) + 1;
				ft_strlcpy(data->str, data->backup,
					ft_strlen(data->backup) + 1);
				write(1, data->backup, ft_strlen(data->backup));
			}
		}
		return (1);
	}
	return (0);
}
