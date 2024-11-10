/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:55:35 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 23:11:03 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swap[a - b] the first 2 elements at the top of the stack
** Nothing if stack is empty or just one
** Swap[s] -> swap a and swap b
*/
static void	ft_lst_swap(t_lst *a, t_lst *b)
{
	t_lst	tmp;

	if (!a || !b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;

	b->next = a->next;
	a->next = b;
}

void	ft_swap_a(t_data *lst)
{
	if (!lst->a || !lst->a->next)
		return ;
	ft_lst_swap(lst->a, lst->a->next);
}

void	ft_swap_b(t_data *lst)
{
	if (!lst->b || !lst->b->next)
		return ;
	ft_lst_swap(lst->b, lst->b->next);
}

void	ft_swap_s(t_data *lst)
{
	ft_swap_a(lst);
	ft_swap_b(lst);
}