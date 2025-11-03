/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:04:35 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/02 20:41:50 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

int	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	result;
	int		digits;
	if (!str)
		ft_error();
	i = 0;
	signe = 1;
	result = 0;
	digits = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			signe *= -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		digits = 1;
		result = result * 10 + (str[i++] - 48);
		if ((signe == 1 && result > INT_MAX) || (signe == -1 && -result < INT_MIN))
			ft_error();
	}
	if (!digits || str[i] != '\0')
		ft_error();
	return (signe * result);
}
