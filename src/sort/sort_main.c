/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:34:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/18 20:34:38 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_all(t_data *lst)
{
	int	count;

	count = 0;
	while (lst->b)
	{
		ft_printf("%d |", ++count);
		ft_push_a(lst);
	}
}

static size_t	len_to_pos(t_data *lst, size_t pos)
{
	size_t	len_to;
	t_lst	*tmp;

	len_to = 0;
	tmp = lst->a;
	while (tmp)
	{
		if (tmp->pos == pos)
			break ;
		len_to++;
		tmp = tmp->next;
	}
	return (len_to);
}

static size_t	get_direction(t_data *lst, size_t pos_tomin, size_t pos_tomax)
{
	size_t	len_to_min;
	size_t	len_to_max;

	len_to_min = len_to_pos(lst, pos_tomin);
	len_to_max = len_to_pos(lst, pos_tomax);
	if (len_to_min < len_to_max)
		return (len_to_min);
	else
		return (len_to_max);
}

static void	manage_direction(t_data *lst, size_t pos_tomin, size_t pos_tomax)
{
	size_t	len_lst;

	len_lst = ft_lstsize_int(lst->a);
	if (get_direction(lst, pos_tomax, pos_tomin) < (len_lst / 2))
		ft_rotate_a(lst);
	else
		ft_reverse_rotate_a(lst);
}

static void	manage_move_in_stack(t_data *lst, short direction_move,
		size_t *pos_tomax, size_t *pos_tomin)
{
	if (direction_move == 1)
	{
		ft_push_b(lst);
		ft_rotate_b(lst);
		*pos_tomin = *(pos_tomin)-1;
	}
	else if (direction_move == -1)
	{
		ft_push_b(lst);
		*pos_tomax = *(pos_tomax) + 1;
	}
}

void	ft_sort_main(t_data *lst, size_t size)
{
	size_t	pos_tomin;
	size_t	pos_tomax;

	pos_tomin = (size / 2) - 1;
	pos_tomax = size / 2;
	while (lst->a)
	{
		manage_direction(lst, pos_tomin, pos_tomax);
		if (lst->a->pos == pos_tomin && pos_tomin > 0)
			manage_move_in_stack(lst, 1, &pos_tomax, &pos_tomin);
		else if (lst->a->pos == pos_tomax && pos_tomax <= size - 1)
			manage_move_in_stack(lst, -1, &pos_tomax, &pos_tomin);
	}
	ft_push_a_all(lst);
}
