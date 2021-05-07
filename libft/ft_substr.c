/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:19:30 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/10 12:54:35 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_src;

	if (src == NULL)
		return (NULL);
	len_src = ft_strlen((char *)src);
	if (len == 0 || start >= len_src)
		return (ft_strdup(""));
	if ((len_src - start) < len)
		len = len_src - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, src + start, len + 1);
	return (str);
}
