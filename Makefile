# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 11:29:45 by ludebarn          #+#    #+#              #
#    Updated: 2025/11/07 15:48:46 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRCS = crea_lst.c ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdup.c ft_lstlast.c ft_lstnew.c ft_lstsize.c swap.c push.c \
		ft_putstr.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_error.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_substr.c push_swap.c \
		push_to_b.c reverse_rotate.c rotate.c sort_small_nb.c sort_to_a.c

OBJ_DIR = object

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = gcc
CFLAGS = -g -I ./

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rsc $@ $^

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
