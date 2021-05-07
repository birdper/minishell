/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:08:16 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/02 15:19:01 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst + len - 1;
	s = src + len - 1;
	if (dst == src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (len--)
			*d-- = *s--;
	return (dst);
}
