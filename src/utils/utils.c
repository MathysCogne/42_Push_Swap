/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:19:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/11 00:23:06 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print(t_data lst)
{
	ft_printf("A | B\n");
	ft_printf("-----\n");
	while(lst.a || lst.b)
	{
		if (lst.a)
		{
			ft_printf("%d", lst.a->content);
			lst.a = lst.a->next;
		}
		ft_printf(" - ");
		if (lst.b)
		{
			ft_printf("%d", lst.b->content);
			lst.b = lst.b->next;
		}
		ft_printf("\n");
	}
}

void	manage_error_free(short error, t_data *lst)
{
	if (error == 2)
	{
		ft_printf("DEBUG: Erreur in Alloc struct");
	}
	// TODO: FREE CONTENT LST
	// free(lst->a);
	// free(lst->b);
	if (error == 3)
	{
		ft_printf("DEBUG: Erreur in Parsing");
	}
	ft_put_error_exit();
	free(lst);
}

void	ft_put_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
