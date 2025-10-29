/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:03:08 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/29 07:06:53 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	n;
	size_t	lens;
	size_t	dispo;
	char	*dst;

	lens = ft_strlen(s);
	dispo = (lens - start);
	if (start >= lens)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (len < dispo)
		n = len + 1;
	else
		n = dispo + 1;
	dst = malloc(sizeof(char) * (n));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s[start], n);
	return (dst);
}
// int main(void)
// {
// 	char *str;
// 	str = ft_substr("salut comment ca va?", 6, 7);
// 	printf("%s\n", str);
// }
