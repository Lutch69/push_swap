/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:58:11 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/08 20:01:07 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_to_a(t_list **a, t_list **b, int flag)
{
	int	chunk_pos;
	int	i;

	chunk_pos = ft_lstsize(*b);
	i = 0;
	while ((*b) && chunk_pos >= 0)
	{
		while (chunk_pos != (*b)->index)
		{
			if (check_rotate((*b), chunk_pos) < chunk_pos / 2)
				i += rotate_b(b, flag);
			else
				i += reverse_rotate_b(b, flag);
		}
		i += push_a(a, b, flag);
		chunk_pos--;
	}
	return (i);
}

int	definechunk_size(t_list **a, t_list **b, int lst_size)
{
	t_chunk_data	d;
	int				new_stock;
	t_list			*temp_a;
	t_list			*temp_b;

	new_stock = 2147483647;
	d.i = 1;
	d.stock = lst_size;
	while (d.i++ < lst_size / 5)
	{
		temp_a = ft_lstdup(*a);
		temp_b = ft_lstdup(*b);
		d.stock = push_to_b(&temp_a, &temp_b, d.i, 1);
		d.stock += sort_to_a(&temp_a, &temp_b, 1);
		if (new_stock > d.stock)
		{
			new_stock = d.stock;
			d.ret = d.i;
		}
		ft_lstclear(&temp_a);
		ft_lstclear(&temp_b);
	}
	return (d.ret);
}

int	check_rotate(t_list *lst, int chunk_pos)
{
	int		count_rb;
	t_list	*temp;

	temp = lst;
	count_rb = 0;
	while (temp->index != chunk_pos)
	{
		temp = temp->next;
		count_rb++;
	}
	return (count_rb);
}
