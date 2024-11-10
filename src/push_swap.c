/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:47:54 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 14:50:40 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*init_struct(t_pile *pile)
{
	pile = malloc(sizeof(t_pile));
	if (!pile)
		return (NULL);
	pile->a = NULL;
	pile->b = NULL;
	return (pile);
}

void	push_swap(size_t size, char **arg)
{
	t_pile	pile;

	if (!arg)
		ft_put_error(1);
	if (!init_struct(&pile))
		ft_put_error(2);
	if (parsing(&pile, size, arg))
		ft_put_error(3);
	debug_print(pile);
}
