/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:13:59 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/31 15:53:28 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *lst_a;
	t_list *lst_b;
	lst_b = NULL;
	// while (i < ac)
	// {
	// 	av[i] = ft_strjoin(av[i], av[i + 1]);
	// 	i++;
	// }
	// av = ft_split(av[1], ' ');
	// i = 0;
	// while (av[i])
	// {
	// 	printf("%s\n", av[i]);
	// 	i++;
	// }
	lst_a = crea_lst(ac, av);
	algo (&lst_a, &lst_b);
	// sort_to_a(&lst_a, &lst_b);
	// int len = ft_lstsize(lst_a);
	// while (i < len)
	// {
	// 	printf("%d ", lst_a->index);
	// 	lst_a = lst_a->next;
	// 	i++;
	// }

	// while (lst_a)
	// {
	// 	printf("%d ", lst_a->index);
	// 	lst_a = lst_a->next;
	// }
	return (0);
}
