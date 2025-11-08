/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:13:59 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/08 21:14:35 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_ac(char **str)
{
	int	count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

void	check_double(int ac, char **av, int split)
{
	long	stock;
	long	newstock;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = i + 1;
		stock = ft_atol(av[i]);
		if (stock > INT_MAX || stock < INT_MIN)
			if_split_error(ac, av, split);
		while (j < ac)
		{
			newstock = ft_atol(av[j]);
			if (stock == newstock || stock > INT_MAX || stock < INT_MIN)
				if_split_error(ac, av, split);
			j++;
		}
	}
}

void	check_av(int ac, char **av, int split)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][i] == '-' || av[j][i] == '+')
			i++;
		if (av[j][i] == '\0')
			if_split_error(ac, av, split);
		while (av[j][i])
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
				if_split_error(ac, av, split);
			i++;
		}
		j++;
	}
}

static char	**new_av(char *progname, char **temp, int ac)
{
	char	**new_av;
	int		i;

	i = 0;
	new_av = malloc(sizeof(char *) * (ac + 1));
	if (!new_av)
		ft_error(ac, new_av);
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
	char	**temp;
	int		split;

	split = 0;
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		ac = count_ac(temp) + 1;
		av = new_av(av[0], temp, ac);
		free(temp);
		split = 1;
	}
	check_double(ac, av, split);
	check_av(ac, av, split);
	lst_b = NULL;
	lst_a = crea_lst(ac, av);
	algo(&lst_a, &lst_b);
	if (split)
		free_av(ac, av);
	ft_lstclear(&lst_a);
	return (0);
}
