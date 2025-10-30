# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 11:29:45 by ludebarn          #+#    #+#              #
#    Updated: 2025/10/30 22:24:39 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

LIBFT = libft
LST   = lst
UTILS = utils

SRCS = $(wildcard $(LIBFT)/*.c) $(wildcard $(LST)/*.c) $(wildcard $(UTILS)/*.c)
OBJ_DIR = object
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = gcc
CFLAGS = -I ./

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
