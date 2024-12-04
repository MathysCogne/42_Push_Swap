/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:41:57 by mcogne--          #+#    #+#             */
/*   Updated: 2024/12/04 22:31:15 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"

/*******************************/
/*       CHECKER - BONUS       */
/*******************************/
short	read_make_operation(t_data *lst);

/*******************************/
/*            UTILS            */
/*******************************/
void	manage_free_exit(t_data *lst);

#endif