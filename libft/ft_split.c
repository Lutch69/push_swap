/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:14 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 18:34:48 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

static size_t	ft_countword(char *str, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

static void	ft_freetab(char **newstr, size_t word)
{
	ft_putstr("ERROR404");
	while (word-- > 0)
		free(newstr[word]);
	free(newstr);
}

static int	ft_copy_lines(char **newstr, char *str, char c, size_t word)
{
	size_t	i;
	size_t	count_word;
	size_t	start;

	count_word = 0;
	i = 0;
	while (count_word < word && str[i])
	{
		while (str[i] == c && str[i])
			i++;
		start = i;
		while (str[i] != c && str[i])
			i++;
		if (i - start)
		{
			newstr[count_word] = ft_substr(str, start, i - start);
			if (!newstr[count_word])
			{
				ft_freetab(newstr, count_word);
				return (0);
			}
			count_word++;
		}
	}
	return (1);
}

char	**ft_split(char *s1, char c)
{
	char	**newstr;
	size_t	word;

	if (!s1)
		return (NULL);
	word = ft_countword(s1, c);
	newstr = malloc(sizeof(char *) * (word + 1));
	if (!newstr)
		return (NULL);
	newstr[word] = NULL;
	if (ft_copy_lines(newstr, s1, c, word))
		return (newstr);
	else
		return (NULL);
}

// int	main(void)
// {
// 	char	**newstr;
// 	int		i;

// 	i = 0;
// 	newstr = ft_split("Bonjour comment ca va ?", 32);
// 	while (newstr[i])
// 	{
// 		printf("%s\n", newstr[i]);
// 		i++;
// 	}
// 	while (i > 0)
// 	{
// 		free(newstr[i]);
// 		i--;
// 	}
// 	free(newstr);
// }
