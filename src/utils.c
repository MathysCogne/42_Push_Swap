/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:19:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 14:54:28 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print(t_pile pile)
{
	int	i;

	i = 0;
	ft_printf("A | B\n");
	ft_printf("-----\n");
	while(i < 4 || pile.a[i])
	{
		ft_printf("%d - %d\n", pile.a[i], pile.b[i]);
		i++;
	}
}

void	ft_put_error(short error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == 1)
		exit(EXIT_FAILURE);
	if (error == 2)
	{
		ft_printf("DEBUG: Erreur in Alloc struct");
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{
		ft_printf("DEBUG: Erreur in Parsing");
		exit(EXIT_FAILURE);
	}
}
