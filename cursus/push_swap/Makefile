# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2022/12/05 20:48:38 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
AR			= ar -rcs
SRCS		= ft_push_swap.c main.c ft_list.c
MAIN		= main.c
LIBFT		= libft/libft.a
OBJS		= ${SRCS:.c=.o}

${NAME}	:
			@${MAKE} -C libft/
			@${CC} -c ${CFLAGS} ${SRCS}
			@mv ${LIBFT} ${NAME}
			@${AR} ${NAME} ${OBJS}
			@${CC} ${MAIN} ${NAME} -o ${NAME}
			@echo "Compiled push_swap"
all		:	${NAME}

clean	:
		@${MAKE} -C libft/ clean
		@${RM} ${OBJS}

fclean	:	clean
		@${RM} -f ${NAME}
		@${MAKE} -C libft/ fclean
		@echo "Cleaned push_swap"

re		:	fclean all

.PHONY: re fclean clean all 