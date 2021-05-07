/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:28:27 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/03 16:06:57 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	ft_strncat(char *dst, const char *src, size_t dstsize, int n)
{
	size_t	countdst;
	size_t	countsrc;
	int		i;

	countsrc = ft_strlen((char *)src);
	countdst = ft_strlen(dst);
	if (dstsize <= countdst)
		return (countsrc + dstsize);
	while (*dst)
		dst++;
	i = 0;
	while (*src && (dstsize - countdst - 1) && i < n)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
		i++;
	}
	*dst = '\0';
	return (countsrc + countdst);
}
