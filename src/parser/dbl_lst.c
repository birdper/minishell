/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:25:16 by wjarr             #+#    #+#             */
/*   Updated: 2021/05/01 13:42:18 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_2list	*ft_dbl_lstnew(char *content)
{
	t_2list	*dbl_lst;

	dbl_lst = (t_2list *)malloc(sizeof(t_2list));
	if (dbl_lst == NULL)
		return (NULL);
	dbl_lst->content = content;
	dbl_lst->next = NULL;
	dbl_lst->prev = NULL;
	return (dbl_lst);
}

void	ft_dbl_lstadd_front(t_2list **dbl_lst, t_2list *new)
{
	new->next = *dbl_lst;
	if (*dbl_lst != NULL)
		(*dbl_lst)->prev = new;
	*dbl_lst = new;
}

int	ft_dbl_lstsize(t_2list *lst)
{
	t_2list	*tmp;
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
