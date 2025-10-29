/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 07:36:51 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/29 08:03:03 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;
	if (!lst_a)
		return ;
	temp = *lst_b;
	*lst_b = *lst_a;
	*lst_a = (*lst_a)->next;
	(*lst_b)->next = temp;
	ft_putstr("pb");
}
void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;
	if (!lst_b)
		return ;
	temp = *lst_a;
	*lst_a = *lst_b;
	*lst_b = (*lst_b)->next;
	(*lst_a)->next = temp;
	ft_putstr("pa");
}

