/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:13:59 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/28 11:35:04 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *lst;
	if (ac == 2)
	{
		ft_strjoin(av[0], av[1]);
		av = ft_split(av[0], ' ');
	}
	lst = crea_lst(ac, av);
	(void)lst;
	return (0);
}
