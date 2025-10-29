# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 11:29:45 by ludebarn          #+#    #+#              #
#    Updated: 2025/10/29 07:20:14 by lucasdebarn      ###   ########.fr        #
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
CFLAGS = -Wall -Werror -Wextra -g -I ./

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
