/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:34:26 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/15 16:49:16 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a_all(t_data *lst, size_t size)
{
	int	count;

	count = 0;
	(void)size;
	while (lst->b)
	{
		ft_printf("%d |", ++count);
		ft_push_a(lst);
	}
}

size_t	manage_direction(t_data *lst, size_t pos)
{
	size_t	len_to;
	size_t	size_lst;
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
	size_lst = ft_lstsize_int(lst->a);
	if (len_to < size_lst / 2)
		return (0);
	return (len_to);
}

void	ft_sort_main(t_data *lst, size_t size)
{
	size_t	pos;
	int		count;

	count = 0;
	(void)size;
	pos = 1;
	while (lst->a)
	{
		ft_printf("%d |", ++count);
		if (!manage_direction(lst, pos))
			ft_rotate_a(lst);
		else
			ft_reverse_rotate_a(lst);
		if (lst->a->pos == pos)
		{
			pos++;
			ft_printf("%d |", ++count);
			ft_push_b(lst);
		}
	}
	ft_push_a_all(lst, size);
}
