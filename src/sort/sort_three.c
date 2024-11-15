/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:52:41 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/13 20:24:25 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data *lst)
{
	if (!lst->a->next)
		return ;
	if (lst->a->content > lst->a->next->content)
		ft_swap_a(lst);
	if (!lst->a->next->next)
		return ;
	if (lst->a->next->content > lst->a->next->next->content)
	{
		ft_reverse_rotate_a(lst);
		if (lst->a->content > lst->a->next->content)
			ft_swap_a(lst);
	}
	else if (lst->a->content > lst->a->next->content)
		ft_swap_a(lst);
}
