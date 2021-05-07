/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:28:35 by nbirdper          #+#    #+#             */
/*   Updated: 2021/04/12 18:00:24 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *src_arr, int length, int (*f)(int))
{
	int		i;
	int		*dst_arr;

	i = 0;
	dst_arr = (int *)malloc(length * sizeof(int));
	while (i < length)
	{
		dst_arr[i] = (*f)(src_arr[i]);
		i++;
	}
	return (dst_arr);
}
