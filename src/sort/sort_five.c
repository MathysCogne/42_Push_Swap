/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:44:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/06 16:33:27 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_value(t_lst *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

void	ft_sort_five(t_data *lst)
{
	int	min_value;

	if (!lst->a || !lst->a->next || !lst->a->next->next)
		return ;
	while (ft_lstsize_int(lst->a) > 3)
	{
		min_value = find_min_value(lst->a);
		if (lst->a->content == min_value)
			ft_push_b(lst);
		else
		{
			if (lst->a->next->content == min_value)
				ft_rotate_a(lst);
			else
				ft_reverse_rotate_a(lst);
		}
	}
	ft_sort_three(lst);
	if (lst->b->content > lst->b->next->content)
	{
		ft_push_a(lst);
		ft_rotate_b(lst);
	}
	ft_push_a(lst);
}
