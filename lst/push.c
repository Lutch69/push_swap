/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 07:36:51 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/31 15:10:19 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

int	push_b(t_list **lst_a, t_list **lst_b, int flag)
{
	t_list	*temp;

	if (!lst_a || !*lst_a)
		return (0);
	temp = *lst_b;
	*lst_b = *lst_a;
	*lst_a = (*lst_a)->next;
	(*lst_b)->next = temp;
	if (flag == 0)
	{
		ft_putstr("pb\n");
		return (0);
	}
	return (1);
}
int	push_a(t_list **lst_a, t_list **lst_b, int flag)
{
	t_list	*temp;

	if (!lst_b || !*lst_b)
		return (0);
	temp = *lst_a;
	*lst_a = *lst_b;
	*lst_b = (*lst_b)->next;
	(*lst_a)->next = temp;
	if (flag == 0)
	{
		ft_putstr("pa\n");
		return (0);
	}
	return (1);
}
