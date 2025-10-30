/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:58:11 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 17:41:52 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkchunk_size(int lst_size)
{
	int ret;

	ret = 50;
	if (lst_size <= 120 && lst_size >= 60)
		ret = 50;
	// else if (lst_size <= 200 && lst_size >= 121)
	// 	ret = 30;
	// else if (lst_size <= 320 && lst_size >= 201)
	// 	ret = 40;
	// else if (lst_size <= 420 && lst_size >= 321)
	// 	ret = 50;
	return (ret);
}

int	check_rrb(t_list **lst, int chunk_pos)
{
	int	count_rrb;

	count_rrb = 0;
	while ((*lst)->index != chunk_pos)
		count_rrb += reverse_rotate_b(lst, 1);
	return(count_rrb);
}

int	check_rb(t_list **lst, int chunk_pos)
{
	int	count_rb;

	count_rb = 0;
	while ((*lst)->index != chunk_pos)
		count_rb += rotate_b(lst, 1);
	return(count_rb);
}
int	sort_to_a(t_list **lst_a, t_list **lst_b)
{
	int	chunk_pos;

	chunk_pos = ft_lstsize(*lst_b);
	int i = 0;
	while (*lst_b && chunk_pos > 0)
	{
		while (chunk_pos != (*lst_b)->index)
		{
		if (check_rb(lst_b, chunk_pos) < (check_rrb(lst_b, chunk_pos)))
			i += rotate_b(lst_b, 0);
		else if (check_rb(lst_b, chunk_pos) > (check_rrb(lst_b, chunk_pos)))
			i += reverse_rotate_b(lst_b, 0);
		}
		i += push_a(lst_a, lst_b, 1);
		chunk_pos--;
	}
	return (i);
}
