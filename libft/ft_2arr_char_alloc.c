/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2arr_char_alloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 03:51:03 by nbirdper          #+#    #+#             */
/*   Updated: 2021/04/03 20:59:45 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_2arr_char_alloc(size_t h, size_t w)
{
	char	**arr;
	char	*start;
	size_t	i;

	h++;
	arr = (char **)malloc(h * sizeof(char *) + h * w * sizeof(char));
	if (arr == NULL)
		return (NULL);
	start = (char *)arr + h * sizeof(char *);
	i = 0;
	while (i < h - 1)
	{
		arr[i] = start + i * w;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
