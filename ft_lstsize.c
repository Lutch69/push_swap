/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:15:43 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/07 11:01:52 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*int	main(void)
{
	t_list *node1 = ft_lstnew("1,2,3,");
	t_list *node2 = ft_lstnew("4,5,6,");
	t_list *header = ft_lstnew("7,8,9");
	ft_lstadd_front(&header, node2);
	ft_lstadd_front(&header, node1);
	printf("%d\n", ft_lstsize(header));
}*/
