/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:24:52 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/12 22:12:54 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	load_pile(t_data *lst, size_t size, char **arg)
{
	size_t	i;

	i = 0;
	lst->a = ft_lstnew_int(ft_atoi(arg[i + 1]));
	if (!lst->a)
		return (1);
	i++;
	lst->b = NULL;
	while (i < size)
	{
		ft_lstadd_int_back(&lst->a, ft_lstnew_int(ft_atoi(arg[i + 1])));
		i++;
	}
	return (0);
}

static short	no_duplicate(size_t size, char **arg)
{
	size_t	i;
	size_t	j;
	int		tmp_arg;

	i = 1;
	while (i < size)
	{
		tmp_arg = ft_atoi(arg[i]);
		j = i + 1;
		while (j < size)
		{
			
			if (tmp_arg == ft_atoi(arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static short	is_int(size_t size, char **arg)
{
	size_t		i;
	char		*str;

	i = 1;
	while (i < size)
	{
		if (ft_strlen(arg[i]) > 12)
			return (1);
		if (ft_atoll(arg[i]) > INT_MAX || ft_atoll(arg[i]) < INT_MIN)
			return (1);
		str = arg[i];
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (1);
			str++;
		}
		i++;
	}
	return (0);
}

short	parsing(t_data *lst, size_t size, char **arg)
{
	if (is_int(size, arg))
		return (1);
	if (no_duplicate(size, arg))
		return (1);
	if (load_pile(lst, size - 1, arg))
		return (1);
	return (0);
}