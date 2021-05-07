/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:09:28 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/12 16:41:10 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char		*s;
	unsigned char			*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*d = *s;
		d++;
		if (*s == (unsigned char)c)
			return (d);
		s++;
	}
	return (NULL);
}
