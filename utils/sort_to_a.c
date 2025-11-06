/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:58:11 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/06 13:22:21 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_to_a(t_list **lst_a, t_list **lst_b, int flag)
{
	int	chunk_pos;
	int	i;

	chunk_pos = ft_lstsize(*lst_b);
	i = 0;
	while ((*lst_b) && chunk_pos >= 0)
	{
		while (chunk_pos != (*lst_b)->index)
		{
			if (check_rotate((*lst_b), chunk_pos) < chunk_pos / 2)
				i += rotate_b(lst_b, flag);
			else
				i += reverse_rotate_b(lst_b, flag);
		}
		i += push_a(lst_a, lst_b, flag);
		chunk_pos--;
	}
	return (i);
}

int	definechunk_size(t_list **lst_a, t_list **lst_b, int lst_size)
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
	while (i++ < lst_size / 3)
	{
		temp_a = ft_lstdup(*lst_a);
		temp_b = ft_lstdup(*lst_b);
		stock = push_to_b(&temp_a, &temp_b, i, lst_size, 1);
		stock += sort_to_a(&temp_a, &temp_b, 1);
		if (new_stock > stock)
		{
			new_stock = stock;
			ret = i;
		}
		ft_lstclear(&temp_a);
		ft_lstclear(&temp_b);
	}
	return (ret);
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
