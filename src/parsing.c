/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:24:52 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 01:48:59 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
// Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
// un int, ou encore, s’il y a des doublons.
#include "push_swap.h"

static short	load_pile(t_pile *pile, size_t size, char **arg)
{
	size_t	i;

	i = 0;
	size++; // POUR CANCEL LE NOM DU PRGM
	while (i < size)
	{
		pile->a[i] = ft_atoi(arg[i]);
		i++;
	}
	return (0);
}

static short	no_duplicate(size_t size, char **arg)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size - 1)
	{
		while ()
		j = i + 1;
		
	}
	return (0);
}

static short	is_int(size_t size, char **arg)
{
	size_t	i;

	i = 0;
	size++; // POUR CANCEL LE NOM DU PRGM
	while (i < size - 1)
	{
		while(*arg[i])
		{
			if (*arg[i] < '0' && *arg[i] > '9')
				return (1);
			arg[i]++;
		}
		i++;
	}
	return (0);
}

short	parsing(t_pile *pile, size_t size, char **arg)
{
	if (is_int (size, arg))
	{
		ft_printf("ICI");
		return (1);
	}
	if (no_duplicate (size, arg))
	{
		ft_printf("ICI");
		return (1);
	}
	if (load_pile(pile, size, arg))
		return (1);
	return (0);
}