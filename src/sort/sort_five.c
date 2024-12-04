/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:44:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 23:19:34 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_min_value(t_lst *lst)
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
	size_t	min_value;

	if (!lst->a || !lst->a->next || !lst->a->next->next)
		return ;
	while (ft_lstsize_int(lst->a) > 3)
	{
		min_value = find_min_value(lst->a);
		if ((size_t)lst->a->content == min_value)
			ft_push_b(lst);
		else
			ft_rotate_a(lst);
	}
	ft_sort_three(lst);
	ft_push_a(lst);
	ft_push_a(lst);
	if (lst->a->content > lst->a->next->content)
		ft_swap_a(lst);
}
