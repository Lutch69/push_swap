/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:40:03 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/29 07:07:39 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

t_list	*ft_lstnew(int val)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->val = val;
	res->next = NULL;
	return (res);
}
// int	main(void)
// {
// 	t_list *node1;
// 	node1 = ft_lstnew("abc");
// 	printf("%s\n", (char *)node1->content);
// }
