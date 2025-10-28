# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 11:29:45 by ludebarn          #+#    #+#              #
#    Updated: 2025/10/28 13:00:56 by ludebarn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

LIBC =	crea_lst.c push_swap.c ft_substr.c ft_strlen.c ft_strlcpy.c \
		ft_strlcat.c ft_strjoin.c ft_split.c ft_lstsize_bonus.c \
		ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstclear_bonus.c \
		ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_atoi.c \
		ft_strdup.c ft_lstdelone_bonus.c

SRCS = ${LIBC}


OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}


all: 	${NAME}

clean:
		@rm -f ${OBJS}

fclean:	clean;
		@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
