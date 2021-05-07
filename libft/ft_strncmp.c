/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirpder@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:55:03 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/11 18:55:14 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	ret;

	while (n--)
	{
		ret = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (ret || *s1 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (ret);
}
