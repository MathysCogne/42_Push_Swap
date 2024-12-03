/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:25:08 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/28 22:52:41 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	init_segment(t_segment *seg, size_t total_size)
{
	seg->size = get_optimal_size(total_size);
	seg->start = 0;
	seg->rot_count = 0;
}

/* 
** Rotation and segment progress 
*/
int	handle_segment_rotation(t_data *lst, size_t *rot_count, size_t stack_size)
{
	ft_rotate_a(lst);
	(*rot_count)++;
	return (*rot_count >= stack_size);
}

/* 
** Update segment values for next iteration 
*/
void	update_segment(t_data *lst, t_segment *seg)
{
	seg->stack_size = ft_lstsize_int(lst->a);
	seg->end = seg->start + seg->size;
	seg->pivot = find_pivot(lst, seg->start, seg->end);
}

/* 
** Complete rotation cycle if needed
*/
void	handle_rotation(t_data *lst, size_t *rot_count, size_t stack_size)
{
	while (*rot_count < stack_size)
	{
		ft_reverse_rotate_a(lst);
		(*rot_count)++;
	}
	*rot_count = 0;
}
