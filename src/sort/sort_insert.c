/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:27:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/13 20:19:33 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Insertion Sort - For 5 - 10 values
** 
** Best: O(n) (Already sorted) - Worst: O(n^2) (Reverse sorted)
**
** Insertion sort works by gradually building a sorted list by inserting 
** each new element into its correct position among the already sorted elements.
*/

void ft_insert_sort(t_data *lst)
{
	while (lst->a)
		ft_push_b(lst);

	while (lst->b)
	{
		debug_print(*lst);
		if (!lst->a || lst->b->content <= lst->a->content)
			ft_push_a(lst);
		else
		{
			while (lst->b && lst->b->content > lst->a->content)
				ft_rotate_b(lst);
			ft_push_a(lst);
			while (lst->b && lst->b->content < lst->a->content)
			

			
				ft_reverse_rotate_b(lst);
		}
	}
}

// PSEUDO CODE

// TANT QUE a != NULL
// 	ft_push_b(lst)
// 	SI b == NULL OU b.content >= a.content
// 		ft_push_a(lst)
// 	SINON
// 		TANT QUE b != NULL ET b.content < a.content
// 			ft_rotate_b(lst)
// 		ft_push_a(lst)
// 		TANT QUE b != NULL ET b.content > a.content
// 			ft_reverse_rotate_b(lst)

// TANT QUE b != NULL
// 	ft_push_a(lst)