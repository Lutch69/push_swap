/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:25:24 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/06 13:24:57 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_ra(t_list *lst, int chunk_size, int flag)
// {
// 	int		count_ra;
// 	t_list	*temp;

// 	temp = ft_lstdup(lst);
// 	count_ra = 0;
// 	while ((temp)->index > chunk_size)
// 	{
// 		rotate_a(&temp, flag);
// 		count_ra++;
// 	}
// 	ft_lstclear(&temp);
// 	return (count_ra);
// }

// int	check_rra(t_list *lst, int chunk_size, int flag)
// {
// 	t_list	*temp;
// 	int		count_rra;

// 	temp = ft_lstdup(lst);
// 	count_rra = 0;
// 	while ((temp)->index > chunk_size)
// 	{
// 		reverse_rotate_a(&temp, flag);
// 		count_rra++;
// 	}
// 	ft_lstclear(&temp);
// 	return (count_rra);
// }

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
