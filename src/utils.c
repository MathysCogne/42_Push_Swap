/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:19:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 00:23:18 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_error(short error)
{
	ft_putstr_fd("Error\n", 0);
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
