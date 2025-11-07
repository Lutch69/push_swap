/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:49:35 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/07 11:42:40 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_sort(t_list **lst_a)
{
	t_list	*temp;
	int		stock;

	temp = (*lst_a);
	while (temp->next != NULL)
	{
		stock = temp->index;
		temp = temp->next;
		if (temp->index < stock)
			return (0);
	}
	return (1);
}

void	sort_2(t_list **lst)
{
	if ((*lst)->index < (*lst)->next->index)
		swap_a(lst);
}

void	sort_3(t_list **lst_a)
{
	t_list	*last;

	last = ft_lstlast((*lst_a));
	if ((*lst_a)->index > (*lst_a)->next->index)
		swap_a(lst_a);
	if ((*lst_a)->next->index > last->index)
		reverse_rotate_a(lst_a, 0);
	if ((*lst_a)->index > (*lst_a)->next->index)
		swap_a(lst_a);
}

void	sort_5(t_list **lst_a, t_list **lst_b)
{
	int		count;

	count = 1;
	while (*lst_a)
	{
		if ((*lst_a)->index == count)
		{
			push_b(lst_a, lst_b, 0);
			count++;
			if (count == 3)
			{
				sort_3(lst_a);
				break ;
			}
		}
		if (check_rotate((*lst_a), count) < (ft_lstsize(*lst_a) / 2))
			rotate_a(lst_a, 0);
		else
			reverse_rotate_a(lst_a, 0);
	}
	push_a(lst_a, lst_b, 0);
	push_a(lst_a, lst_b, 0);
}
