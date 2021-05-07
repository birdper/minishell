/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:55:38 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/20 16:04:53 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_countlines(const char *src, char c)
{
	size_t		countlines;

	countlines = 0;
	while (*src != 0)
	{
		if (*src != c && (*(src + 1) == c || *(src + 1) == '\0'))
			countlines++;
		src++;
	}
	return (countlines);
}

static char	**ft_init_arr(const char *src, char c)
{
	size_t		countlines;
	char		**arr;

	if (src == NULL)
		return (NULL);
	countlines = ft_get_countlines(src, c);
	arr = (char **)malloc((countlines + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

int	fill_substr(char **p_arr, const char *start, size_t len, char **arr)
{
	if (len != 0)
	{
		*p_arr = ft_substr(start, 0, len);
		if (*p_arr == NULL)
		{
			ft_free_2arr(arr);
			return (1);
		}
	}
	return (0);
}

char	**ft_split(const char *src, char c)
{
	char			**arr;
	const char		*start;
	const char		*r_del;
	uint32_t		len;
	size_t			i;

	arr = ft_init_arr(src, c);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*src != 0)
	{
		while (*src == c && *src != '\0')
			src++;
		start = src;
		while (*src != c && *src != '\0')
			src++;
		r_del = src;
		len = r_del - start;
		if (fill_substr(&arr[i++], start, len, arr))
			return (NULL);
	}
	arr[i] = NULL;
	return (arr);
}
