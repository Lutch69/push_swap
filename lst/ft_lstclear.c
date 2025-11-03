/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:55:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/31 15:10:56 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

// void	ft_free(void *content)
// {
// 	if (content)
// 		free(content);
// }

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*header;

// 	node1 = ft_lstnew(ft_strdup("1,2,3,"));
// 	node2 = ft_lstnew(ft_strdup("4,5,6,"));
// 	header = ft_lstnew(ft_strdup("7,8,9,"));
// 	ft_lstadd_front(&header, node2);
// 	ft_lstadd_front(&header, node1);
// 	ft_lstclear(&header, ft_free);
// }
