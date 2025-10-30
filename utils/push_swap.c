/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:13:59 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 17:52:49 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *lst_a;
	t_list *lst_b;
	// while (ac == 2)
	// {
	// 	ft_strjoin(av[0], av[1]);
	// 	av = ft_split(av[0], ' ');
	// lst_a = crea_lst(ac, av);
	// while (lst_a)
	// {
	// 	printf("%d ", lst_a->val);
	// 	lst_a = lst_a->next;
	// }
	lst_b = NULL;
	algo (&lst_a, &lst_b);
	// while (lst_a->next != NULL)
	// {
	// 	printf("%d ", lst_a->index);
	// 	lst_a = lst_a->next;
	// }
	// printf("%d", lst_b->val);
	// printf ("valeur: [%d], index: [%d]\n", lst_a->val, lst_a->index);
	// printf ("valeur: [%d], index: [%d]\n", lst_a->next->val, lst_a->next->index);
	// printf ("valeur: [%d], index: [%d]\n", lst_a->next->next->val, lst_a->next->next->index);
	// push_b(&lst_a, &lst_b);
	// // printf ("apres rotate : valeur: [%d], index: [%d]\n", lst_a->val, lst_a->index);
	// printf ("apres rotate : valeur: [%d], index: [%d]\n", lst_b->val, lst_b->index);
	// // printf ("valeur: [%d], index: [%d]\n", lst_a->next->val, lst_a->next->index);
	// // printf ("valeur: [%d], index: [%d]\n", lst_a->next->next->val, lst_a->next->next->index);
	// // push_a(&lst_a, &lst_b);
	// push_a(&lst_a, &lst_b);
	// printf ("valeur: [%d], index: [%d]\n", lst_a->val, lst_a->index);
	// printf ("valeur: [%d], index: [%d]\n", lst_a->next->val, lst_a->next->index);
	// printf ("valeur: [%d], index: [%d]\n", lst_a->next->next->val, lst_a->next->next->index);
	return (0);
}
