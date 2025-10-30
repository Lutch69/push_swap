/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:09 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/30 15:18:34 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

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

//Fonction lst
void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstnew(int val);
t_list	*crea_lst(int ac, char **av);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

//fonction libft
int	ft_atoi(char *str);
char	**ft_split(char *s1, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
void	ft_putstr(char *str);

//fonction de tri
int		push_a(t_list **lst_a, t_list **lst_b, int flag);
int		push_b(t_list **lst_a, t_list **lst_b, int flag);
void	swap_a(t_list **lst_a);
void	swap_b(t_list **lst_b);
void	swap_ss(t_list **lst_a, t_list **lst_b);
int		rotate_a(t_list **lst_a, int flag);
int		rotate_b(t_list **lst_b, int flag);
int		rotate_r(t_list **lst_a, t_list **lst_b, int flag);
int		reverse_rotate_a(t_list **lst_a, int flag);
int		reverse_rotate_b(t_list **lst_b, int flag);
int		reverse_rotate_r(t_list **lst_a, t_list **lst_b, int flag);

//fonction pour algo
int	push_to_b(t_list **lst_a, t_list **lst_b, int chunk_size, int lst_size);
int	sort_to_a(t_list **lst_a, t_list **lst_b);
int	checkchunk_size(int lst_size);
void	algo(t_list **lst_a, t_list **lst_b);
int	check_rrb(t_list **lst_b, int chunk_pos);
int	check_rb(t_list **lst_b, int chunk_pos);
int	check_ra(t_list **lst, int chunk_pos);
int	check_rra(t_list **lst, int chunk_pos);

#endif
