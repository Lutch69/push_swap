/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:25:24 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/03 01:13:33 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **lst_a, t_list **lst_b, int chunk_size, int lst_size)
{
	int	chunk_pos;
	int	incr_chunk;

	incr_chunk = chunk_size;
	chunk_pos = 0;
	while (chunk_pos < lst_size - 1)
	{
		while (chunk_pos < chunk_size - 1 && (*lst_a))
		{
			if ((*lst_a) && (*lst_a)->index <= chunk_pos)
			{
				push_b(lst_a, lst_b, FLAG);
				chunk_pos++;
				if ((*lst_a) && (*lst_a)->index > chunk_size)
					rotate_r(lst_a, lst_b, FLAG);
				else
					rotate_b(lst_b, FLAG);
			}
			else if ((*lst_a) && (*lst_a)->index < chunk_size)
			{
				push_b(lst_a, lst_b, FLAG);
				chunk_pos++;
			}
			else
				rotate_a(lst_a, FLAG);
		}
		chunk_size += incr_chunk;
	}
}

void	algo(t_list **lst_a, t_list **lst_b)
{
	int	lst_size;
	int	chunk_size;

	if (!lst_a || !*lst_a)
		return ;
	lst_size = ft_lstsize(*lst_a);
	chunk_size = checkchunk_size(lst_a, lst_b, lst_size);
	push_to_b(lst_a, lst_b, chunk_size, lst_size);
	sort_to_a(lst_a, lst_b);
}
