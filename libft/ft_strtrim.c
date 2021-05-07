/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:04:56 by nbirdper          #+#    #+#             */
/*   Updated: 2021/01/30 01:13:08 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates (with malloc(3)) and returns a copy of
**	’s1’ with the characters specified in ’set’ removed
**	from the beginning and the end of the string.
** @param 'src' The string to be trimmed.
** @param 'set' The reference set of characters to trim.
** @return The trimmed string. NULL if the allocation fails.
*/

static int	ft_chrcmp(char src, const char *set)
{
	while (*set != 0)
	{
		if ((unsigned char)src == *(unsigned char *)set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *src, const char *set)
{
	char	*str;
	int		start;
	int		end;
	int		len;

	if (set == NULL || src == NULL)
		return (NULL);
	end = ft_strlen((char *)src) - 1;
	start = 0;
	while (ft_chrcmp(src[start], set))
		start++;
	while (ft_chrcmp(src[end], set))
		end--;
	end++;
	len = end - start;
	if (len <= 0)
		return (ft_strdup(""));
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &src[start], len + 1);
	return (str);
}
