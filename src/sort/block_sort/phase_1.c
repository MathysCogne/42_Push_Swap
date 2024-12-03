/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:07:12 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/03 19:31:29 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ** Phase 1: Segmentation and Pre-sorting
** 
** Strategy: Quick-sort inspired approach
** - Divides stack A into segments of optimal size
** - Uses pivot within each segment for partial sorting
** - Elements < pivot go to bottom of B
** - Elements > pivot stay at top of B
** - Creates a rough sort in stack B
*/

#include "push_swap.h"

/* 
** Calculate pivot
*/
size_t	find_pivot(t_data *lst, size_t start, size_t end)
{
	t_lst	*current;
	size_t	min;
	size_t	max;

	current = lst->a;
	min = end;
	max = start;
	while (current && current->pos >= start && current->pos <= end)
	{
		if (current->pos < min)
			min = current->pos;
		if (current->pos > max)
			max = current->pos;
		current = current->next;
	}
	return ((min + max) / 2);
}

/* 
** Push to B
*/
static void	push_segment(t_data *lst, size_t *segment_start,
	size_t pivot, size_t *rot_count)
{
	ft_push_b(lst);
	if (lst->b->pos < pivot)
		ft_rotate_b(lst);
	(*segment_start)++;
	*rot_count = 0;
}

/* 
** Manage rotatation and segment
*/
static void	process_element(t_data *lst, t_segment *seg)
{
	if (lst->a->pos <= seg->end)
	{
		if (seg->rot_count > seg->stack_size / 2)
			handle_rotation(lst, &seg->rot_count, seg->stack_size);
		push_segment(lst, &seg->start, seg->pivot, &seg->rot_count);
	}
	else if (handle_segment_rotation(lst, &seg->rot_count, seg->stack_size))
	{
		seg->start += seg->size;
		seg->rot_count = 0;
	}
}

/* 
Phase 1: Split A into segments and send to B 
*/
void	push_to_b_and_sort(t_data *lst, size_t size)
{
	t_segment	seg;

	init_segment(&seg, size);
	while (lst->a)
	{
		update_segment(lst, &seg);
		process_element(lst, &seg);
	}
}
