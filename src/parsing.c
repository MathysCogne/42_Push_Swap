/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:24:52 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 14:57:45 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
// Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
// un int, ou encore, s’il y a des doublons.
// CHECK INT PLS
#include "push_swap.h"

static short	load_pile(t_pile *pile, size_t size, char **arg)
{
	size_t	i;

	pile->a = (int *)malloc(size * sizeof(int));
	if (!pile->a)
		return (1);
	pile->b = (int *)malloc(size * sizeof(int));
	if (!pile->b)
	{
		free(pile->a);
		return (1);
	}
	i = 0;
	while (i < size)
	{
		pile->a[i] = ft_atoi(arg[i + 1]); // Skip PRGM NAME
		i++;
	}
	return (0);
}

static short	no_duplicate(size_t size, char **arg)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static short	is_int(size_t size, char **arg)
{
	size_t	i;
	char	*str;

	i = 1;
	while (i < size)
	{
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

short	parsing(t_pile *pile, size_t size, char **arg)
{
	if (is_int(size, arg))
		return (1);
	if (no_duplicate(size, arg))
		return (1);
	if (load_pile(pile, size - 1, arg))
		return (1);
	return (0);
}