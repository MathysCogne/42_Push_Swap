/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:38:28 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 22:44:18 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	result_sort(short sorted, t_data *lst)
{
	if (!sorted)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	manage_free_exit(lst);
	exit(EXIT_SUCCESS);
}

static void	ft_checker(size_t size, char **arg)
{
	t_data	lst;

	if (!arg)
		ft_put_error_exit();
	lst = (t_data){0};
	if (parsing(&lst, size, arg))
		manage_error_free(3, &lst);
	find_pos(&lst, size);
	if (read_make_operation(&lst))
		manage_error_free(4, &lst);
	if (is_sort_and_b_empty(&lst))
		result_sort(0, &lst);
	result_sort(1, &lst);
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
