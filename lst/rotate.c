/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:07:31 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/30 22:32:47 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

static void	ft_rotate(t_list **lst)
{
	t_list	*temp_end;
	t_list	*temp_start;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp_end = ft_lstlast(*lst);
	temp_start = *lst;
	(*lst) = temp_start->next;
	temp_end->next = temp_start;
	temp_start->next = NULL;
}

int	rotate_a(t_list **lst_a, int flag)
{
	ft_rotate(lst_a);
	if (flag == 0)
	{
		ft_putstr("ra\n");
		return (0);
	}
	else
		return (1);
}

int	rotate_b(t_list **lst_b, int flag)
{
	ft_rotate(lst_b);
	if (flag == 0)
	{
		ft_putstr("rb\n");
		return (0);
	}
	else
		return (1);
}

int	rotate_r(t_list **lst_a, t_list **lst_b, int flag)
{
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	if (flag == 0)
	{
		ft_putstr("rr\n");
		return (0);
	}
	else
		return (1);
}
