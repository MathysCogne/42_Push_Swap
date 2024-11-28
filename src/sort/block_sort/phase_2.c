/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:23:01 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/28 22:17:01 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ** Phase 2: Final Sorting (Inspring of Selection sort)
** 
** Strategy: Modified Selection Sort
** - Finds maximum value in stack B
** - Rotates B to bring max to top using optimal direction
** - Pushes max back to A
** - Optimizes adjacent elements in B when beneficial
** - Results in fully sorted stack A
*/

#include "push_swap.h"

/* 
** Find max value in B 
*/
static int	find_max_position(t_data *lst, size_t *pos)
{
	t_lst	*current;
	size_t	max_value;
	size_t	current_pos;

	current = lst->b;
	max_value = 0;
	current_pos = 0;
	*pos = 0;
	while (current)
	{
		if (current->pos > max_value)
		{
			max_value = current->pos;
			*pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (max_value);
}

/* 
** Optimize B by swapping elements if neff
*/
static void	optimize_rotations(t_data *lst)
{
	if (lst->b && lst->b->next)
	{
		if (lst->b->pos < lst->b->next->pos)
		{
			if (!lst->b->next->next || lst->b->next->pos
				> lst->b->next->next->pos)
				ft_swap_b(lst);
		}
	}
}

/* 
** Find best rotation for B
*/
static void	handle_max_rotation(t_data *lst, size_t *max_pos, size_t size)
{
	if (*max_pos <= size / 2)
	{
		ft_rotate_b(lst);
		(*max_pos)--;
	}
	else
	{
		ft_reverse_rotate_b(lst);
		if (*max_pos + 1 == size)
			*max_pos = 0;
		else
			*max_pos = *max_pos + 1;
	}
}

/* 
Phase 2: Go back lements back to A and final sort 
*/
void	push_to_a(t_data *lst)
{
	size_t	max_pos;
	size_t	size;

	while (lst->b)
	{
		size = ft_lstsize_int(lst->b);
		find_max_position(lst, &max_pos);
		while (max_pos > 0)
			handle_max_rotation(lst, &max_pos, size);
		optimize_rotations(lst);
		ft_push_a(lst);
	}
}
