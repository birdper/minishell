/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2arr_int_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 03:51:16 by nbirdper          #+#    #+#             */
/*   Updated: 2021/04/03 21:00:10 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**ft_2arr_int_alloc(size_t h, size_t w)
{
	int		**arr;
	int		*start;
	size_t	i;

	arr = (int **)malloc(h * sizeof(int *) + h * w * sizeof(int));
	if (arr == NULL)
		return (NULL);
	start = (int *)((char *)arr + h * sizeof(int *));
	i = 0;
	while (i < h)
	{
		arr[i] = start + i * w;
		i++;
	}
	return (arr);
}
