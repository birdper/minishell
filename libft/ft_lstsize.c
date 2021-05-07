/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbirdper <nbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:54:27 by nbirdper          #+#    #+#             */
/*   Updated: 2020/11/18 13:11:20 by nbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		size;

	tmp = lst;
	if (lst == NULL)
		return (0);
	size = 1;
	while (tmp->next != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
