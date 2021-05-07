/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:20:15 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/02 01:57:45 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	tputchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void	make_backup(t_reader *data)
{
	char	*tmp;

	if (data->first == 0)
	{
		tmp = data->backup;
		data->backup = ft_strdup(data->str);
		free(tmp);
	}
}

int	check_read(char *buf, int res)
{
	if (res == -1)
		exit(1);
	buf[res] = '\0';
	return (0);
}
