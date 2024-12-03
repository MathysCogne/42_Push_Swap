/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:38:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/03 22:12:58 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_data	*init_struct(t_data *lst)
{
	lst = malloc(sizeof(t_data));
	if (!lst)
		return (NULL);
	lst->a = NULL;
	lst->b = NULL;
	return (lst);
}

void	win()
{
	ft_printf("OK !");
}

void	ko()
{
	ft_printf("KO !");
}

static void	ft_checker(size_t size, char **arg)
{
	t_data	lst;

	if (!arg)
		ft_put_error_exit();
	if (!init_struct(&lst))
		manage_error_free(2, &lst);
	if (parsing(&lst, size, arg))
		manage_error_free(3, &lst);
	find_pos(&lst, size);
	if (read_make_operation(&lst))
		manage_error_free(4, &lst); // TODO DEFINE ERROR 4
	debug_print(lst);
	if (ft_already_sort(&lst))
	{
		ko();
		return ;
	}
	win();
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_put_error_exit();
		return (1);
	}
	ft_checker(argc, argv);
	return (0);
}
