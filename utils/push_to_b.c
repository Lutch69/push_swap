/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:25:24 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/04 09:36:31 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ra(t_list *lst, int chunk_size)
{
	int		i;
	int		size;
	t_list	*temp;

	if (!lst)
		return (-1);
	size = ft_lstsize(lst);
	i = 0;
	temp = lst;
	while (i < size)
	{
		if (temp->index <= chunk_size)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

int	opti_rotate(t_list **lst_a, int chunk_size, int flag)
{
	int	ra;
	int	rra;
	int i;
	if (!lst_a)
		return(-1);
	i = 0;
	ra = check_ra((*lst_a), chunk_size);
	if (ra < 0)
		return (-1);
	rra = ft_lstsize((*lst_a)) - ra;
	if (ra <= rra)
		while(ra >= 0)
		{
			i += rotate_a(lst_a, flag);
			ra--;
		}
	else
		while (rra >= 0)
		{
			i += reverse_rotate_a(lst_a, flag);
			rra--;
		}
	return (i);
}

int	push_to_b(t_list **lst_a, t_list **lst_b, int chunk_size,
		int lst_size, int flag)
{
	int	chunk_pos;
	int	i;
	int	incr_chunk;

	i = 0;
	incr_chunk = chunk_size;
	chunk_pos = 0;
	while (chunk_pos < lst_size - 1)
	{
		while (chunk_pos < chunk_size - 1 && (*lst_a))
		{
			if ((*lst_a) && (*lst_a)->index <= chunk_pos)
			{
				i += push_b(lst_a, lst_b, flag);
				chunk_pos++;
				if ((*lst_a) && (*lst_a)->index > chunk_size)
					i += rotate_r(lst_a, lst_b, flag);
				else
					i += rotate_b(lst_b, flag);
			}
			else if ((*lst_a) && (*lst_a)->index < chunk_size)
			{
				i += push_b(lst_a, lst_b, flag);
				chunk_pos++;
			}
			if (*lst_a)
				i += opti_rotate(lst_a, chunk_size, flag);
		}
		chunk_size += incr_chunk;
	}
	return (i);
}

void	algo(t_list **lst_a, t_list **lst_b)
{
	int	lst_size;
	int	chunk_size;

	if (!lst_a || !*lst_a)
		return ;
	lst_size = ft_lstsize(*lst_a);
	chunk_size = definechunk_size(lst_a, lst_b, lst_size);
	push_to_b(lst_a, lst_b, chunk_size, lst_size, 0);
	sort_to_a(lst_a, lst_b, 0);
}
