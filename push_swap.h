/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:09 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/27 19:21:11 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

// #include "../libft/libft.h"
// #include "../printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct c_list
{
	int				val;
	int				index;
	struct c_list	*next;
}					t_list;

int	main(int ac, char **av);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(int val);
t_list	*crea_lst(int ac, char **av);
t_list	*ft_lstlast(t_list *lst);
int	ft_atoi(const char *str);
char	**ft_split(char *s1, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
#endif
