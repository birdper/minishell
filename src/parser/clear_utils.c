/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:27:09 by wjarr             #+#    #+#             */
/*   Updated: 2021/04/28 22:27:32 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	clear_cmd(t_list **list)
{
	t_data		*dtmp;
	t_list		*lsttmp;
	t_redirect	*rdtmp;
	t_list		*newtmp;

	lsttmp = *list;
	while (lsttmp)
	{
		dtmp = lsttmp->content;
		ft_free_2arr(dtmp->args);
		newtmp = dtmp->redirects;
		while (newtmp)
		{
			rdtmp = newtmp->content;
			free(rdtmp->rd_file);
			newtmp = newtmp->next;
		}
		ft_lstclear(&dtmp->redirects, free);
		lsttmp = lsttmp->next;
	}
	ft_lstclear(list, free);
	return (0);
}

void	clear_data(t_data *data)
{
	t_data		*dtmp;
	t_redirect	*rdtmp;
	t_list		*newtmp;

	dtmp = data;
	if (dtmp->args)
		ft_free_2arr(dtmp->args);
	newtmp = dtmp->redirects;
	while (newtmp)
	{
		rdtmp = newtmp->content;
		free(rdtmp->rd_file);
		newtmp = newtmp->next;
	}
	ft_lstclear(&dtmp->redirects, free);
}

void	ft_lstclear_no_content(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
