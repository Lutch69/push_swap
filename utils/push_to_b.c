/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:25:24 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 17:46:08 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rra(t_list **lst, int chunk_pos)
{
	int	count_rra;

	count_rra = 0;
	while ((*lst)->index != chunk_pos)
		count_rra += reverse_rotate_a(lst, 1);
	return(count_rra);
}

int	check_ra(t_list **lst, int chunk_pos)
{
	int	count_ra;

	count_ra = 0;
	while ((*lst)->index != chunk_pos)
		count_ra += rotate_a(lst, 1);
	return(count_ra);
}
int	push_to_b(t_list **lst_a, t_list **lst_b, int chunk_size, int lst_size)
{
	int	chunk_pos;
	int i = 0;

	chunk_pos = 1;
		while (*lst_a && chunk_pos < lst_size)
		{
			while (*lst_a && chunk_pos < chunk_size)
			{
				if ((*lst_a)->index <= chunk_pos)
				{
					i += push_b(lst_a, lst_b, 0);
					chunk_pos++;
					if ((*lst_a)->index > chunk_size)
						i += rotate_r(lst_a, lst_b, 0);
					else
						i+= rotate_b(lst_b, 0); // a check
				}
				else if ((*lst_a)->index < chunk_size)
				{
					i += push_b(lst_a, lst_b, 0);
					chunk_pos++;
				}
				else
					i += reverse_rotate_a(lst_a, 0);
			}
			chunk_size += checkchunk_size(lst_size);
		}
		return (i);
}
void	algo(t_list **lst_a, t_list **lst_b)
{
	int lst_size;
	int chunk_size;
	int i = 0;

	if (!lst_a || !*lst_a)
		return ;
	lst_size = ft_lstsize(*lst_a);
	chunk_size = checkchunk_size(lst_size);
	i += push_to_b(lst_a, lst_b, chunk_size, lst_size);
	i += sort_to_a(lst_a, lst_b);
		// printf ("[[[[%d]]]]", i);
}
