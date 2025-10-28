/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:12:07 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/28 19:31:39 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list *swap;

	if (!*lst || !lst)
		return (NULL);

	swap = (*lst);
	(*lst) = (*lst)->next;
	(*lst) = swap;
}
void	swap_a(t_list **lst_a)
{

}

void	push_a(t_list **lst_a)
{

}
