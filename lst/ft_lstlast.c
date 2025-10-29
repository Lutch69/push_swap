/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:43:37 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/29 07:07:31 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*int	main(void)
{
	t_list *node1 = ft_lstnew("1,2,3,");
	t_list *node2 = ft_lstnew("4,5,6,");
	t_list *header = ft_lstnew("7,8,9");
	t_list *last;
	ft_lstadd_front(&header, node2);
	ft_lstadd_front(&header, node1);
	printf("%s\n", (char *)header->content);
	last = ft_lstlast(header);
	printf("%s\n", (char *)last->content);
}*/
