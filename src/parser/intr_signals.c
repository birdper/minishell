/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intr_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 23:21:52 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:07:36 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	tgetterm(struct termios *term)
{
	tgetent(0, "xterm-256color");
	tcgetattr(0, term);
}

void	sig_interrupt(int status)
{
	status = 1;
	ft_putendl_fd("", 1);
}

void	sig_quit(int status)
{
	status = 1;
	ft_putstr_fd("Quit: ", 2);
	ft_putnbr_fd(SIGQUIT, 2);
	ft_putendl_fd("", 1);
}
