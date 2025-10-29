/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:54:27 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/29 07:07:04 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	if (!lst && !new)
		return ;
	temp = ft_lstlast(*lst);
	if (temp)
		temp->next = new;
	else
		*lst = temp;
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew("1,2,3,");
// 	t_list *node2 = ft_lstnew("4,5,6,");
// 	t_list *header = ft_lstnew("7,8,9,");
// 	ft_lstadd_front(&header, node2);
// 	ft_lstadd_front(&header, node1);
// 	ft_lstadd_back(&header, ft_lstnew("10,11,12"));
// 	while(header->next)
// 	{
// 		printf("%s\n", (char *)header->content);
// 		header = header->next;
// 	}
// 		printf("%s\n", (char *)header->content);
// }
