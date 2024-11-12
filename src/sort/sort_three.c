/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:52:41 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/12 19:06:55 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ? Radix Sort

void	ft_sort_two_in_b(t_data *lst)
{
	// ft_push_b(lst);
	// ft_push_b(lst);
	if (lst->b && lst->b->next && lst->b->content < lst->b->next->content)
		ft_swap_b(lst);
	// ft_push_a(lst);
	// ft_push_a(lst);
}

void ft_sort_three(t_data *lst)
{
	t_lst *tmp;

	ft_push_b(lst);
	ft_push_b(lst);
	ft_sort_two_in_b(lst);
	tmp = lst->a;
	ft_sort_two(lst);
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			ft_swap_a(lst);
		tmp = tmp->next;
		ft_sort_two(lst);
	}
}
