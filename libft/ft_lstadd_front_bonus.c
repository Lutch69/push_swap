/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:40:19 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/27 16:15:25 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	new->next = temp;
	*lst = new;
}
// int	main(void)
// {
// 	t_list *node1 = ft_lstnew("1,2,3,");
// 	t_list *node2 = ft_lstnew("4,5,6,");
// 	t_list *header = ft_lstnew("7,8,9");
// 	ft_lstadd_front(&header, node2);
// 	ft_lstadd_front(&header, node1);
// 	printf("%s", (char *)header->content);
// 	printf("%s", (char *)header->next->content);
// 	printf("%s", (char *)header->next->next->content);
// }
