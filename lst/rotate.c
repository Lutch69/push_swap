/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:07:31 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/29 08:42:27 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

void	ft_rotate(t_list **lst)
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


