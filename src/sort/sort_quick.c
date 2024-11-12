/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcogne-- <mcogne--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:28:51 by mcogne--          #+#    #+#             */
/*   Updated: 2024/11/13 00:33:09 by mcogne--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Quick Sort - For 10 to 100 values
** 
** Average: O(n log n) - Worst: O(n^2)
**
** Sort work by selecting a 'pivot' element from the list. 
** With two Sub lst, according to whether they are less than or greater than the pivot.
** Sub lst sort recursively.
*/

function quick_sort(lst, low, high)
	SI low < high
		pivot_index = partition(lst, low, high)
		// Trie avant le pivot
		quick_sort(lst, low, pivot_index - 1)
		// Trier après le pivot
		quick_sort(lst, pivot_index + 1, high)

function partition(lst, low, high)
	// Choix de l'élément pivot
	pivot = get_element_at(lst, high)
	i = low - 1
	POUR j = low À high - 1
		SI get_element_at(lst, j) < pivot
			i++
			swap_elements(lst, i, j)
	swap_elements(lst, i + 1, high)
	RETOURNER i + 1

function get_element_at(lst, index)
	// Find index
	current = lst.a
	count = 0
	TANT QUE current != NULL ET count < index
		current = current.next
		count++
	RETOURNER current.content

function swap_elements(lst, index1, index2)
	element1 = get_element_at(lst, index1)
	element2 = get_element_at(lst, index2)
	TANT QUE lst.a.content != element1
		ft_rotate_a(lst)
	TANT QUE lst.a.content != element2
		ft_rotate_a(lst)
	ft_swap_a(lst)
	// Back to a
	TANT QUE lst.a.content != element1
		ft_reverse_rotate_a(lst)
	TANT QUE lst.a.content != element2
		ft_reverse_rotate_a(lst)

quick_sort(lst, 0, size(lst.a) - 1)