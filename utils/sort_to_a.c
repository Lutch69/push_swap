/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:58:11 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 22:31:53 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push_to_b(t_list *lst_a, t_list *lst_b, int chunk_size, int lst_size)
{
	int	chunk_pos;
	int i = 0;
	int incr_chunk = chunk_size;

	chunk_pos = 0;
		while (lst_a && chunk_pos < lst_size - 1)
		{
			while (chunk_pos < chunk_size - 1 && lst_a)
			{
				if ((lst_a)->index <= chunk_pos)
				{
					i += push_b(&lst_a, &lst_b, 1);
					chunk_pos++;
					if ((lst_a)->index > chunk_size)
						i += rotate_r(&lst_a, &lst_b, 1);
					else
						i+= rotate_b(&lst_b, 1);
				}
				else if ((lst_a)->index < chunk_size)
				{
					i += push_b(&lst_a, &lst_b, 1);
					chunk_pos++;
				}
				else
					i += rotate_a(&lst_a, 1);
			}
			chunk_size += incr_chunk;
		}
		return (i);
}

int	checkchunk_size(t_list *lst_a, t_list *lst_b, int lst_size)
{
	int	ret;
	int	i;
	int stock;

	i = 0;
	stock = check_push_to_b(lst_a, lst_b, i, lst_size);
	ret = lst_size;
	while (i < lst_size)
	{
		if (check_push_to_b(lst_a, lst_b, i, lst_size) < stock)
		{
			stock = check_push_to_b(lst_a, lst_b, i, lst_size);
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	check_rrb(t_list *lst, int chunk_pos)
{
	int	count_rrb;

	count_rrb = 0;
	while ((lst)->index != chunk_pos)
		count_rrb += reverse_rotate_b(lst, 1);
	return(count_rrb);
}

int	check_rb(t_list *lst, int chunk_pos)
{
	int	count_rb;

	count_rb = 0;
	while ((lst)->index != chunk_pos)
		count_rb += rotate_b(lst, 1);
	return(count_rb);
}
int	sort_to_a(t_list **lst_a, t_list **lst_b)
{
	int	chunk_pos;

	t_list *temp;

	chunk_pos = ft_lstsize(*lst_b);
	int i = 0;
	while (*lst_b && chunk_pos >= 0)
	{
		temp = *lst_a;
		while (chunk_pos != (*lst_b)->index)
		{
		if (check_rb(temp, chunk_pos) < (check_rrb(temp, chunk_pos)))
			i += rotate_b(lst_b, FLAG);
		else if (check_rb(temp, chunk_pos) > (check_rrb(temp, chunk_pos)))
			i += reverse_rotate_b(lst_b, FLAG);
		}
		i += push_a(lst_a, lst_b, FLAG);
		chunk_pos--;
	}
	return (i);
}
