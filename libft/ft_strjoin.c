/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:54:50 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/10 19:46:59 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	dstsize;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	dstsize = len_s1 + len_s2 + 1;
	str = (char *)ft_calloc(dstsize, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, s1, dstsize);
	ft_strlcat(str, s2, dstsize);
	return (str);
}
