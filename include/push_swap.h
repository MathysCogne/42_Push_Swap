/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:48:15 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 00:20:17 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_pile
{
	int	*a;
	int	*b;
}		t_pile;

/*******************************/
/*          PUSH SWAP          */
/*******************************/
void	push_swap(size_t size, char **arg);

short	parsing(t_pile *pile, size_t size, char **arg);

/*******************************/
/*            UTILS            */
/*******************************/
void	ft_put_error(short error);

#endif