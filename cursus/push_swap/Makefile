# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2023/01/12 14:55:10 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
AR			= ar -rcs
SRCS		= ft_push_swap.c main.c ft_list_utils.c ft_list_utils_2.c ft_list_utils_3.c ft_list_utils_4.c ft_list_utils_5.c ft_push_swap.c
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