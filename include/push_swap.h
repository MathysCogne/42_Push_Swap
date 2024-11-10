/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:48:15 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/10 23:58:49 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

/*******************************/
/*           STRUCT            */
/*******************************/
typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}					t_lst;

typedef struct s_data
{
	t_lst	*a;
	t_lst	*b;
}			t_data;

/*******************************/
/*          PUSH SWAP          */
/*******************************/
void	push_swap(size_t size, char **arg);

short	parsing(t_data *lst, size_t size, char **arg);

/*******************************/
/*          OPERATION          */
/*******************************/
void	ft_swap_a(t_data *lst);
void	ft_swap_b(t_data *lst);
void	ft_swap_s(t_data *lst);

void	ft_push_a(t_data *lst);
void	ft_push_b(t_data *lst);

/*******************************/
/*            UTILS            */
/*******************************/
void	manage_error_free(short error, t_data *lst);
void	ft_put_error_exit(void);
void	debug_print(t_data lst);

t_lst	*ft_lstnew_int(int content);
void	ft_lstadd_int_back(t_lst **lst, t_lst *new);
void	ft_lstadd_int_front(t_lst **lst, t_lst *new);

#endif