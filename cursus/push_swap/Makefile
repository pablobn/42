# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2022/11/24 20:08:48 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
AR			= ar -rcs
SRCS		= ft_push_swap.c main.c
MAIN		= main.c
LIBFT		= libft/libft.a
OBJS		= ${SRCS:.c=.o}

${NAME}	:
			@${MAKE} -C libft/
			${CC} -c ${CFLAGS} ${SRCS}
			mv ${LIBFT} ${NAME}
			${AR} ${NAME} ${OBJS}
			${CC} ${MAIN} ${NAME} -o ${NAME}

all		:	${NAME}

clean	:
		@${MAKE} -C libft/ clean
		${RM} ${OBJS}

fclean	:	clean
		${RM} -f ${NAME}
		@${MAKE} -C libft/ fclean

re		:	fclean all

.PHONY: re fclean clean all 