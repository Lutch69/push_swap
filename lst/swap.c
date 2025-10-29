/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:12:07 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/29 07:05:45 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

static void	ft_swap(t_list **lst)
{
	t_list *first;
	t_list *second;

	if (!lst || !*lst || !(*lst)->next)
		return ;

	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}
void	swap_a(t_list **lst_a)
{
	ft_swap(lst_a);
	ft_putstr("sa");
}

void	swap_b(t_list **lst_b)
{
	ft_swap(lst_b);
	ft_putstr("sb");
}
void	swap_ss(t_list **lst_a, t_list **lst_b)
{
	ft_swap(lst_a);
	ft_swap(lst_b);
	ft_putstr("ss");
}
