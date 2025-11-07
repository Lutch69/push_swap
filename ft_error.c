/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:32:38 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/07 15:36:03 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		free(av[i]);
		i++;
	}
	free(av);
	write (2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

void	free_av(int ac, char **new_av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		free(new_av[i]);
		i++;
	}
	free(new_av);
}
