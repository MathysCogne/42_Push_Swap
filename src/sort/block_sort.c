/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:23:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/20 01:55:05 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_op_count;

static size_t	get_optimal_size(size_t stack_size)
{
	if (stack_size <= 101)
		return (10);
	return (26);
}

/*
** Find max number in b
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
** Push numbers to B in sorted segment
** Split A into ordered segments in B
*/
static void	push_to_b_and_sort(t_data *lst, size_t size)
{
	size_t	size_seg;
	size_t	segment_start;
	size_t	segment_end;

	size_seg = get_optimal_size(size);
	segment_start = 0;
	while (lst->a)
	{
		segment_end = segment_start + size_seg;
		if (lst->a->pos <= segment_end)
		{
			ft_push_b(lst);
			if (lst->b->pos < segment_end - (size_seg / 2))
				ft_rotate_b(lst);
			segment_start++;
			g_op_count++;
		}
		else
		{
			ft_rotate_a(lst);
			g_op_count++;
		}
	}
}

/*
** Find max and rotate
** Push back numbers to A in descending order
*/
static void	push_to_a(t_data *lst)
{
	size_t	max_pos;
	size_t	size;

	while (lst->b)
	{
		size = ft_lstsize_int(lst->b);
		find_max_position(lst, &max_pos);
		
		while (max_pos > 0)
		{
			if (max_pos <= size / 2)
			{
				ft_rotate_b(lst);
				max_pos--;
			}
			else
			{
				ft_reverse_rotate_b(lst);
				if (max_pos + 1 == size)
					max_pos = 0;
				else
					max_pos = max_pos + 1;
			}
			g_op_count++;
		}
		ft_push_a(lst);
		g_op_count++;
	}
}

void	ft_block_sort(t_data *lst, size_t size)
{
	g_op_count = 0;
	push_to_b_and_sort(lst, size);
	push_to_a(lst);
	ft_printf("\nCOUNT OPE: %d\n", g_op_count);
}
