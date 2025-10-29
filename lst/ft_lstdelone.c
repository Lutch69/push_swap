/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:35:01 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/29 07:07:23 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "utils/push_swap.h"

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst)
// 		return ;
// 	del (lst->content);
// 	free (lst);
// }

// void	ft_free(void *content)
// {
// 	if(content)
// 		free(content);
// }

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew(ft_strdup("1,2,3,"));
// 	t_list *node2 = ft_lstnew(ft_strdup("4,5,6,"));
// 	t_list *header = ft_lstnew(ft_strdup("7,8,9,"));
// 	ft_lstadd_front(&header, node2);
// 	ft_lstadd_front(&header, node1);
// 	ft_lstdelone(header, ft_free);
// }
