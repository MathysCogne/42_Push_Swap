/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:23:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 23:20:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Block Sort Algorithm
** hybrid algorithm for Push_Swap
**
** 1.  Block sorting: Divides data into manageable segments
** 1.2 With Quick-sort inspired: Uses pivots for pre-sorting segments
** 2.  Selection sort: For final phase when bringing elements back
**
*/
size_t	get_optimal_size(size_t stack_size)
{
	if (stack_size <= 101)
		return (13);
	if (stack_size <= 499)
		return (20);
	return (29);
}

void	ft_block_sort(t_data *lst, size_t size)
{
	push_to_b_and_sort(lst, size);
	push_to_a(lst);
}
