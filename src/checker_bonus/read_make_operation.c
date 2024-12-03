/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_make_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:59:07 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/03 22:15:45 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static short	make_input(char *input, t_data *lst)
{
	if (!ft_strncmp(input, "sa\n", 3))
		ft_swap_a(lst);
	else if (!ft_strncmp(input, "sb\n", 3))
		ft_swap_b(lst);
	else if (!ft_strncmp(input, "ss\n", 3))
		ft_swap_s(lst);
	else if (!ft_strncmp(input, "pa\n", 3))
		ft_push_a(lst);
	else if (!ft_strncmp(input, "pb\n", 3))
		ft_push_b(lst);
	else if (!ft_strncmp(input, "ra\n", 3))
		ft_rotate_a(lst);
	else if (!ft_strncmp(input, "rb\n", 3))
		ft_rotate_b(lst);
	else if (!ft_strncmp(input, "rr\n", 3))
		ft_rotate_r(lst);
	else if (!ft_strncmp(input, "rra\n", 4))
		ft_reverse_rotate_a(lst);
	else if (!ft_strncmp(input, "rrb\n", 4))
		ft_reverse_rotate_b(lst);
	else if (!ft_strncmp(input, "rrr\n", 4))
		ft_reverse_rotate_r(lst);
	else
		return (1);
	return (0);
}

static short	valid_input(char *input)
{
	char	**valid_input;
	int		i;

	if (!input)
		return (0);
	valid_input = (char *[]){"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	i = 0;
	while (valid_input[i])
	{
		if (!ft_strncmp(input, valid_input[i], ft_strlen(valid_input[i])))
			return (1);
		i++;
	}
	return (0);
}

short	read_make_operation(t_data *lst)
{
	char	*input;

	(void)lst;
	input = get_next_line(0);
	while(input)
	{
		if (!valid_input(input))
			return (1);
		if (make_input(input, lst))
			return (1);
		free(input);
		input = get_next_line(0);
	}
	if (input)
		free(input);
	return (0);
}
