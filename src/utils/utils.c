/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:19:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 22:47:24 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print(t_data lst)
{
	ft_printf("A | B\n");
	ft_printf("-----\n");
	while (lst.a || lst.b)
	{
		if (lst.a)
		{
			ft_printf("%d / %d", lst.a->content, lst.a->pos);
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

void	manage_free_exit(t_data *lst)
{
	ft_lst_free(&lst->a);
	ft_lst_free(&lst->b);
}

void	manage_error_free(short error, t_data *lst)
{
	if (error >= 3)
		manage_free_exit(lst);
	ft_put_error_exit();
}

void	ft_put_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
