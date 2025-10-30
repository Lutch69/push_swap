/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:25:24 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 22:52:39 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rra(t_list *lst, int chunk_pos)
{
	int	count_rra;

	count_rra = 0;
	while ((lst)->index != chunk_pos)
		count_rra += reverse_rotate_a(lst, 1);
	return(count_rra);
}

int	check_ra(t_list *lst, int chunk_pos)
{
	t_list *temp;

	temp = lst;
	int	count_ra;

	count_ra = 0;
	while ((lst)->index != chunk_pos)
		count_ra += rotate_a(lst, 1);
	return(count_ra);
}
int	push_to_b(t_list **lst_a, t_list **lst_b, int chunk_size, int lst_size)
{
	int	chunk_pos;
	int i = 0;
	int incr_chunk = chunk_size;

	chunk_pos = 0;
		while (*lst_a && chunk_pos < lst_size - 1)
		{
			while (chunk_pos < chunk_size - 1 && (*lst_a))
			{
				if ((*lst_a)->index <= chunk_pos)
				{
					i += push_b(lst_a, lst_b, FLAG);
					chunk_pos++;
					if ((*lst_a)->index > chunk_size)
						i += rotate_r(lst_a, lst_b, FLAG);
					else
						i+= rotate_b(lst_b, FLAG);
				}
				else if ((*lst_a)->index < chunk_size)
				{
					i += push_b(lst_a, lst_b, FLAG);
					chunk_pos++;
				}
				else
					i += rotate_a(lst_a, FLAG);
			}
			chunk_size += incr_chunk;
		}
		return (i);
}
void	algo(t_list **lst_a, t_list **lst_b)
{
	int lst_size;
	int i = 0;
	int	chunk_size;

	t_list *temp_a = *lst_a;
	t_list *temp_b = *lst_b;
	if (!lst_a || !*lst_a)
		return ;
	lst_size = ft_lstsize(*lst_a);
	chunk_size = checkchunk_size(temp_a, temp_b, lst_size);
	i += push_to_b(lst_a, lst_b, chunk_size, lst_size);
	i += sort_to_a(lst_a, lst_b);
		// printf ("[[[[%d]]]]", i);
}
