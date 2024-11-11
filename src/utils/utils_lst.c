/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:34:17 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/11 16:10:28 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


size_t	ft_lstsize_int(t_lst *lst)
{
	size_t	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_lst	*ft_lstnew_int(int content)
{
	t_lst	*new_lst;

	new_lst = malloc(sizeof(t_lst));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_lstadd_int_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstadd_int_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
