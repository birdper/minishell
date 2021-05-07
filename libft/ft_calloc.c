/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:55:41 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/10 19:24:36 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	size_t	i;
	size_t	nbytes;

	nbytes = count * size;
	i = 0;
	arr = (char *)malloc(nbytes);
	if (arr == NULL)
		return (NULL);
	while (i < nbytes)
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *)arr);
}
