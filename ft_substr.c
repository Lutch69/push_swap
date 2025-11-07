/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:03:08 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/07 11:02:15 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
