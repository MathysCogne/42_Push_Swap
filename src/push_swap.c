/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:47:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/11 16:00:31 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*init_struct(t_data *lst)
{
	lst = malloc(sizeof(t_data));
	if (!lst)
		return (NULL);
	lst->a = NULL;
	lst->b = NULL;
	return (lst);
}

void	push_swap(size_t size, char **arg)
{
	t_data	lst;

	if (!arg)
		ft_put_error_exit();
	if (!init_struct(&lst))
		manage_error_free(2, &lst);
	if (parsing(&lst, size, arg))
		manage_error_free(3, &lst);
	// ft_swap_a(&lst);
	// ft_push_b(&lst);
	// ft_rotate_a(&lst);
	ft_reverse_rotate_a(&lst);
	debug_print(lst);
}
