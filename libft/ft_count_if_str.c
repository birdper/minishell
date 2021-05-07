/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 02:41:06 by nbirdper          #+#    #+#             */
/*   Updated: 2021/03/06 02:41:08 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_if_str(char *str, int length, int (*f)(int))
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(str[i]))
			count++;
		i++;
	}
	return (count);
}
