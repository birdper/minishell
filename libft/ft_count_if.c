/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjarr <wjarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:29:54 by nbirdper          #+#    #+#             */
/*   Updated: 2021/04/03 21:00:46 by wjarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **arr, int length, int (*f)(char*))
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(arr[i]))
			count++;
		i++;
	}
	return (count);
}
