/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:41:51 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 22:32:39 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

static void	ft_reverse_rotate(t_list **lst)
{
	t_list	*temp_findend;
	t_list	*temp_newstart;
	int		i;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	i = ft_lstsize(*lst) - 1;
	temp_findend = *lst;
	temp_newstart = ft_lstlast(*lst);
	temp_newstart->next = temp_findend;
	while (i > 1)
	{
		temp_findend = temp_findend->next;
		i--;
	}
	temp_findend->next = NULL;
	*lst = temp_newstart;
}

int	reverse_rotate_a(t_list **lst_a, int flag)
{
	ft_reverse_rotate(lst_a);
	if (flag == 0)
	{
		ft_putstr("rra\n");
		return (0);
	}
	else
		return (1);
}

int	reverse_rotate_b(t_list **lst_b, int flag)
{
	ft_reverse_rotate(lst_b);
	if (flag == 0)
	{
		ft_putstr("rrb\n");
		return (0);
	}
	else
		return (1);
}

int	reverse_rotate_r(t_list **lst_a, t_list **lst_b, int flag)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	if (flag == 0)
	{
		ft_putstr("rrr\n");
		return (0);
	}
	return (1);
}
