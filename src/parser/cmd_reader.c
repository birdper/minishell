/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:50:28 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 21:19:07 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_symbol(char *buf, int res, t_reader *data)
{
	char	*tmp;

	data->i += res;
	if (data->i > data->len)
	{
		tmp = data->str;
		data->len *= 2;
		data->str = ft_calloc(data->len, 1);
		ft_strlcpy(data->str, tmp, data->len);
		free(tmp);
	}
	ft_strlcat(data->str, buf, data->i);
	write(1, buf, res);
}

void	data_init(t_reader *data, struct termios *term)
{
	data->first = 0;
	data->len = 100;
	data->str = ft_calloc(data->len, 1);
	data->backup = ft_strdup("");
	data->i = 1;
	data->term = term;
}

int	take_read_symbol(t_reader *data, char *buf, t_2list **tmp_lst, char ***envp)
{
	if (ft_strncmp(buf, "\n", 1) == 0)
		return (-1);
	else if (left_right_button(buf) == 0)
		return (1);
	else if (up_button(tmp_lst, data, buf))
		return (1);
	else if (down_button(tmp_lst, data, buf))
		return (1);
	else if (backspace_button(data, buf))
	{
		make_backup(data);
		return (1);
	}
	else if (signals_isig(buf, data->term, data))
		return (1);
	else if (intr_signal(data, buf, envp))
		return (-1);
	else if ((*buf > '\00' && *buf < ' ') || *buf > '~')
		return (1);
	return (0);
}

char	*cmd_reader(t_2list **history, struct termios *term, char ***envp)
{
	t_reader	data;
	char		buf[100];
	t_2list		*tmp_lst;
	ssize_t		res;
	int			ret;

	tputs(save_cursor, 1, tputchar);
	data_init(&data, term);
	tmp_lst = *history;
	while (1)
	{
		res = read(0, buf, 100);
		if (check_read(buf, res))
			break ;
		ret = take_read_symbol(&data, buf, &tmp_lst, envp);
		if (ret == -1)
			break ;
		else if (ret == 1)
			continue ;
		else
			add_symbol(buf, res, &data);
		make_backup(&data);
	}
		printf("size:%ld buf:%s\n", data.i, data.str);
	free(data.backup);
	return (data.str);
}

char	*create_cmd_line(t_2list **history, char ***envp, struct termios *term)
{
	char	*cmd_line;

	signals_off(term);
	cmd_line = cmd_reader(history, term, envp);
	if (ft_strncmp(cmd_line, "", 1) && ft_strncmp(cmd_line, "\n", 2))
		ft_dbl_lstadd_front(history, ft_dbl_lstnew(ft_strdup(cmd_line)));
	signals_on(term);
	write(1, "\n", 1);
	return (cmd_line);
}
