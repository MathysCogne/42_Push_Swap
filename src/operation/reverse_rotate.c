/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:32:08 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/11 16:50:00 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Reverse Rotate [a - b] -> Swap one position to down
** The last element becomes first
*/
void	ft_reverse_rotate_a(t_data *lst)
{
	t_lst	*tmp;
	t_lst	*last;
	size_t	len;

	if (!lst->a || !lst->a->next)
		return ;
	len = ft_lstsize_int(lst->a);
	tmp = lst->a;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = lst->a;
	lst->a = last;
}

void	ft_reverse_rotate_b(t_data *lst)
{
	t_lst	*tmp;
	t_lst	*last;
	size_t	len;

	if (!lst->b || !lst->b->next)
		return ;
	len = ft_lstsize_int(lst->b);
	tmp = lst->b;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = lst->b;
	lst->b = last;
}

void	ft_reverse_rotate_r(t_data *lst)
{
	ft_reverse_rotate_a(lst);
	ft_reverse_rotate_b(lst);
}