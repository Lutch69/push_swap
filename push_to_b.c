/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:51:08 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/07 16:54:27 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algo_in_a(t_list **lst_a, t_list **lst_b, int chunk_size, int chunk_pos)
{
	int	i;

	i = 0;

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
		else
			i += rotate_a(lst_a,flag);
	}
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
			else
				i += rotate_a(lst_a,flag);
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
	if (lst_size <= 5)
	{
		if (lst_size <= 3)
			sort_3(lst_a);
		else if (lst_size <= 5)
			sort_5(lst_a, lst_b);
		return ;
	}
	chunk_size = definechunk_size(lst_a, lst_b, lst_size);
	push_to_b(lst_a, lst_b, chunk_size, lst_size, 0);
	sort_to_a(lst_a, lst_b, 0);
}
