/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:09 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/07 11:41:59 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef FLAG
#  define FLAG 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct c_list
{
	int				val;
	int				index;
	struct c_list	*next;
}					t_list;

void				ft_error(int ac, char **av);
int					main(int ac, char **av);
void				free_av(int ac, char **new_av);

// Fonction lst
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstdup(t_list *lst);
t_list				*ft_lstnew(int val);
t_list				*crea_lst(int ac, char **av);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);

// fonction libft
int					ft_atoi(char *str);
char				**ft_split(char *s1, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
size_t				ft_strlen(char *s);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
char				*ft_strdup(char *s1);
void				ft_putstr(char *str);
char				*ft_strchr(const char *s, int c);
void				ft_freetab(char **newstr, size_t word);

// fonction sort
int					push_a(t_list **lst_a, t_list **lst_b, int flag);
int					push_b(t_list **lst_a, t_list **lst_b, int flag);
void				swap_a(t_list **lst_a);
void				swap_b(t_list **lst_b);
void				swap_ss(t_list **lst_a, t_list **lst_b);
int					rotate_a(t_list **lst_a, int flag);
int					rotate_b(t_list **lst_b, int flag);
int					rotate_r(t_list **lst_a, t_list **lst_b, int flag);
int					reverse_rotate_a(t_list **lst_a, int flag);
int					reverse_rotate_b(t_list **lst_b, int flag);
int					reverse_rotate_r(t_list **lst_a, t_list **lst_b, int flag);

// fonction algo
int					push_to_b(t_list **lst_a, t_list **lst_b, int chunk_size,
						int lst_size, int flag);
int					sort_to_a(t_list **lst_a, t_list **lst_b, int flag);
void				algo(t_list **lst_a, t_list **lst_b);
void				sort_3(t_list **lst_a);
void				sort_5(t_list **lst_a, t_list **lst_b);
int					no_sort(t_list **lst_a);

// check algo
int					definechunk_size(t_list **lst_a, t_list **lst_b,
						int lst_size);
int					check_rotate(t_list *lst_b, int chunk_pos);
#endif
