/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:51:08 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/08 12:41:08 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_chunk_push(t_list **a, t_list **b, int chunk, int flag)
{
	int	i;

	i = 0;
	i = push_b(a, b, flag);
	if (*a && (*a)->index > chunk)
		i += rotate_r(a, b, flag);
	else
		i += rotate_b(b, flag);
	return (i);
}

static int	push_b_pos(t_list **a, t_list **b, int *pos, int flag)
{
	push_b(a, b, flag);
	(*pos)++;
	return (1);
}

int	push_to_b(t_list **a, t_list **b, int chunk_size, int flag)
{
	int	pos;
	int	i;
	int	incr_chunk;

	i = 0;
	pos = 0;
	incr_chunk = chunk_size;
	while (*a)
	{
		while (pos < chunk_size - 1 && (*a))
		{
			if ((*a) && (*a)->index <= pos)
			{
				i += handle_chunk_push(a, b, chunk_size, flag);
				pos++;
			}
			else if ((*a) && (*a)->index < chunk_size)
				i += push_b_pos(a, b, &pos, flag);
			else
				i += rotate_a(a, flag);
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
	push_to_b(lst_a, lst_b, chunk_size, 0);
	sort_to_a(lst_a, lst_b, 0);
}
