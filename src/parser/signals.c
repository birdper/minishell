/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:42:04 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 15:57:40 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	signals_off(struct termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_lflag &= ~(ISIG);
	tcsetattr(0, TCSANOW, term);
}

void	signals_on(struct termios *term)
{
	(*term).c_lflag |= ICANON;
	(*term).c_lflag |= ECHO;
	(*term).c_lflag |= ISIG;
	tcsetattr(0, TCSANOW, term);
}

int	eof_signal(char *str, struct termios *term)
{
	if (ft_strlen(str) != 0)
		write(2, "\a", 1);
	else
	{
		ft_putendl_fd("exit", 2);
		signals_on(term);
		exit(0);
	}
	return (0);
}

int	intr_signal(t_reader *data, char *buf, char **envp[])
{
	if (ft_strncmp(buf, "\3", 1) == 0)
	{
		ft_memset(data->str, '\0', ft_strlen(data->str));
		set_value_by_key("?", "1", *envp);
		return (1);
	}
	return (0);
}

int	signals_isig(char *buf, struct termios *term, t_reader *data)
{
	if (ft_strncmp(buf, "\4", 1) == 0)
	{
		eof_signal(data->str, term);
		return (1);
	}
	if (ft_strncmp(buf, "\034", 1) == 0)
		return (1);
	return (0);
}
