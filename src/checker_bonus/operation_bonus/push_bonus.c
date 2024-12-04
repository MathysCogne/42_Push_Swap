/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:06:57 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 22:52:18 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push:
** Push the first elements at the top of other stack
** push[a] -> b[1] -> a[1]
** push[b] -> a[1] -> b[1]
** Nothing if stack is empty
*/

void	ft_push_a(t_data *lst)
{
	t_lst	*tmp;

	if (!lst->b)
		return ;
	tmp = lst->b;
	lst->b = lst->b->next;
	ft_lstadd_int_front(&(lst->a), tmp);
}

void	ft_push_b(t_data *lst)
{
	t_lst	*tmp;

	if (!lst->a)
		return ;
	tmp = lst->a;
	lst->a = lst->a->next;
	ft_lstadd_int_front(&(lst->b), tmp);
}
