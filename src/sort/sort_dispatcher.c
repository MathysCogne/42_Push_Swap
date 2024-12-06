/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:23:42 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/06 16:50:39 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** - Sort lst under 3
** - Sort lst under 5
** - Other Block sort
*/

void	ft_sort_dispatcher(t_data *lst, size_t size)
{
	if (size - 1 <= 3)
		ft_sort_three(lst);
	else if (size - 1 == 5)
		ft_sort_five(lst);
	else
	{
		find_pos(lst, size);
		ft_block_sort(lst, size);
	}
}
