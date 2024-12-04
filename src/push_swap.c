/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:47:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 22:44:11 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(size_t size, char **arg)
{
	t_data	lst;

	if (!arg)
		ft_put_error_exit();
	lst = (t_data){0};
	if (parsing(&lst, size, arg))
		manage_error_free(3, &lst);
	if (is_sort_and_b_empty(&lst))
		ft_sort_dispatcher(&lst, size);
	manage_free_exit(&lst);
}
