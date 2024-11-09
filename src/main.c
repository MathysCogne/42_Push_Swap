/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:47:51 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/09 22:39:53 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// • En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
// Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
// un int, ou encore, s’il y a des doublons.

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_put_error(1);
		return (1);
	}
	
	push_swap();
	return (0);
}
