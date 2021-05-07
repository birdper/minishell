/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:30:28 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/19 16:18:11 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_stack;
	size_t	len_needle;
	size_t	i;

	len_needle = ft_strlen((char *)needle);
	len_stack = ft_strlen((char *)haystack);
	if (haystack == NULL || needle == NULL || (len == 0 && len_needle != 0))
		return (NULL);
	if (len_needle == 0)
		return ((char *)haystack);
	if (len_stack >= len_needle)
	{
		i = 0;
		while (i <= len_stack - len)
		{
			if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
				return ((char *)&haystack[i]);
			i++;
		}
	}
	return (NULL);
}
