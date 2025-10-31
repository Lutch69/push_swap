/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:39:27 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/31 15:48:03 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

void	index_lst(t_list *lst, int ac, char **av)
{
	int	check;
	int check_i;
	int index;

	check_i = 1;
	while(lst)
	{
		index = 1;
		check = 1;
		while(check < ac)
		{
			if (ft_atoi(av[check_i]) > ft_atoi(av[check]))
				index++;
			check++;
		}
		lst->index = index;
		lst = lst->next;
		check_i++;
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

