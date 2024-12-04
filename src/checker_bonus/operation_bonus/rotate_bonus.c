/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:13:00 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 22:52:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate [a - b] -> Swap one position up
** The first element becomes the last
*/
void	ft_rotate_a(t_data *lst)
{
	t_lst	*tmp;

	if (!lst->a || !lst->a->next)
		return ;
	tmp = lst->a;
	lst->a = lst->a->next;
	ft_lstadd_int_back(&lst->a, tmp);
	tmp->next = NULL;
}

void	ft_rotate_b(t_data *lst)
{
	t_lst	*tmp;

	if (!lst->b || !lst->b->next)
		return ;
	tmp = lst->b;
	lst->b = lst->b->next;
	ft_lstadd_int_back(&lst->b, tmp);
	tmp->next = NULL;
}

void	ft_rotate_r(t_data *lst)
{
	ft_rotate_a(lst);
	ft_rotate_b(lst);
}
