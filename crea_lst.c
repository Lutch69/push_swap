/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:39:27 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/27 19:23:16 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_lst(t_list *lst, int ac, char **av)
{
	int	i;
	int word;

	i = 0;
	word = 0;
	while(i < ac)
	{
		while(i < ac)
		{
			if (lst->val < lst->next->val)
				i++;
			ac--;
		}
		lst->index = i;
		printf ("%d = %d\n",lst->val, lst->index);
		lst = lst->next;
	}

}

t_list	*crea_lst(int ac, char **av)
{
	int	value;
	int	i;
	t_list	*lst;
	t_list	*new_lst;

	i = 1;
	new_lst = NULL;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		lst = ft_lstnew(value);
		if (!lst)
			return(NULL);
		ft_lstadd_back(&new_lst, lst);
		i++;
	}
	index_lst(new_lst, ac, av);
	return (new_lst);
}

