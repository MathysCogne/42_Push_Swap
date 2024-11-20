/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:16:13 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/20 01:56:19 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find position on stack after sort
**
*/
static t_lst	*find_max(t_data lst)
{
	t_lst	*max;

	max = lst.a;
	while (lst.a)
	{
		if (max->content < lst.a->content)
			max = lst.a;
		lst.a = lst.a->next;
	}
	return (max);
}

void	find_pos(t_data *lst, size_t size)
{
	size_t	pos;
	t_lst	*tmp;
	t_lst	*min;

	pos = 0;
	tmp = lst->a;
	while (tmp)
	{
		tmp->pos = 0;
		tmp = tmp->next;
	}
	while (pos < size - 1)
	{
		tmp = lst->a;
		min = find_max(*lst);
		while (tmp)
		{
			if (tmp->pos == 0 && tmp->content <= min->content)
				min = tmp;
			tmp = tmp->next;
		}
		min->pos = pos + 1;
		pos++;
	}
}
