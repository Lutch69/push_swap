/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:13:59 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/03 14:36:45 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_error(void)
{
	write (2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

void	free_av(char **new_av, size_t ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		free(new_av[ac]);
		i++;
	}
	free(new_av);
}

int	count_ac(char **str)
{
	int	count = 0;
	while (str && str[count])
		count++;
	return(count);
}

char **new_av(char *progname, char **temp, int ac)
{
	char **new_av;
	int	i;

	i = 0;
	new_av = malloc(sizeof(char *) * (ac + 1));
	if (!new_av)
		ft_error();
	new_av[0] = progname;
	while (i < ac)
	{
		new_av[i + 1] = temp[i];
		i++;
	}
	new_av[ac] = NULL;
	return (new_av);
}
int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char **temp;
	int	split;

	split = 0;
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		if (!temp || !temp[0])
			ft_error();
		ac = count_ac(temp) + 1;
		av = new_av(av[0], temp, ac);
		split = 1;
	}
	lst_b = NULL;
	lst_a = crea_lst(ac, av);
	algo(&lst_a, &lst_b);
	if (split)
		free_av(av, ac);
	ft_lstclear(&lst_a);
	return (0);
}
