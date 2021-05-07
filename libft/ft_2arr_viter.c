/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2arr_viter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 03:31:41 by nbirdper          #+#    #+#             */
/*   Updated: 2021/02/05 03:31:44 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_2arr_viter(char **arr, int column, int (*f)(int))
{
	while (*arr)
	{
		if (!f((*arr)[column]))
			return (0);
		arr++;
	}
	return (1);
}