/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:48:38 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/07 11:01:05 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*ret;
	t_list	*node;
	t_list	*temp;

	ret = NULL;
	temp = NULL;
	while (lst)
	{
		node = malloc(sizeof(t_list));
		if (!node)
		{
			ft_lstclear(&ret);
			return (NULL);
		}
		node->val = lst->val;
		node->index = lst->index;
		node->next = NULL;
		if (!ret)
			ret = node;
		else
			temp->next = node;
		temp = node;
		lst = lst->next;
	}
	return (ret);
}
