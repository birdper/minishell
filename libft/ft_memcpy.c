/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:48:03 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/12 16:38:24 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy() function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
** Applications in which dst and src might overlap should use memmove instead.
**
** @return The original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*c_dst;
	const unsigned char		*c_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	c_dst = dst;
	c_src = src;
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}
