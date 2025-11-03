/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:58:11 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/03 01:14:32 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push_to_b(t_list **temp_a, t_list **temp_b, int chunk_size,
		int lst_size)
{
	int	chunk_pos;
	int	i;
	int	incr_chunk;

	i = 0;
	incr_chunk = chunk_size;
	chunk_pos = 0;
	while (chunk_pos < lst_size - 1)
	{
		while (chunk_pos < chunk_size - 1 && (*temp_a))
		{
			if ((*temp_a) && (*temp_a)->index <= chunk_pos)
			{
				i += push_b(temp_a, temp_b, 1);
				chunk_pos++;
				if ((*temp_a) && (*temp_a)->index > chunk_size)
					i += rotate_r(temp_a, temp_b, 1);
				else
					i += rotate_b(temp_b, 1);
			}
			else if ((*temp_a) && (*temp_a)->index < chunk_size)
			{
				i += push_b(temp_a, temp_b, 1);
				chunk_pos++;
			}
			else
				i += rotate_a(temp_a, 1);
		}
		chunk_size += incr_chunk;
	}
	return (i);
}
int	check_sort_to_a(t_list **temp_a, t_list **temp_b)
{
	int	chunk_pos;
	int	i;

	chunk_pos = ft_lstsize(*temp_b);
	i = 0;
	while ((*temp_b) && chunk_pos >= 0)
	{
		while (chunk_pos != (*temp_b)->index)
		{
			if (check_rb((*temp_b), chunk_pos) < chunk_pos / 2)
				i += rotate_b(temp_b, 1);
			else
				i += reverse_rotate_b(temp_b, 1);
		}
		i += push_a(temp_a, temp_b, 1);
		chunk_pos--;
	}
	return (i);
}

int	checkchunk_size(t_list **lst_a, t_list **lst_b, int lst_size)
{
	int		ret;
	int		i;
	int		stock;
	int		new_stock;
	t_list	*temp_a;
	t_list	*temp_b;

	new_stock = 2147483647;
	i = 1;
	ret = lst_size;
	while (i < lst_size / 2)
	{
		temp_a = ft_lstdup(*lst_a);
		temp_b = ft_lstdup(*lst_b);
		stock = check_push_to_b(&temp_a, &temp_b, i, lst_size);
		stock += check_sort_to_a(&temp_a, &temp_b);
		if (new_stock > stock)
		{
			new_stock = stock;
			ret = i;
		}
		i++;
		ft_lstclear(&temp_a);
		ft_lstclear(&temp_b);
	}
	return (ret);
}

int	check_rb(t_list *lst, int chunk_pos)
{
	int		count_rb;
	t_list	*temp;

	temp = lst;
	count_rb = 0;
	while ((temp)->index != chunk_pos)
	{
		temp = temp->next;
		count_rb++;
	}
	return (count_rb);
}
void	sort_to_a(t_list **lst_a, t_list **lst_b)
{
	int	chunk_pos;

	chunk_pos = ft_lstsize(*lst_b);
	while (*lst_b && chunk_pos >= 0)
	{
		while (chunk_pos != (*lst_b)->index)
		{
			if (check_rb(*lst_b, chunk_pos) < chunk_pos / 2)
				rotate_b(lst_b, FLAG);
			else
				reverse_rotate_b(lst_b, FLAG);
		}
		push_a(lst_a, lst_b, FLAG);
		chunk_pos--;
	}
}
