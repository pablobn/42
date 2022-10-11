# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 16:38:46 by pbengoec          #+#    #+#              #
#    Updated: 2022/10/10 16:00:40 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Werror -Wall -Wextra

RM			= rm -f

SRCS		= ft_printf.c ft_putchar_fd.c ft_switch.c ft_putstr_fd.c\
			ft_putnbr_fd.c ft_putnbr_fd_unsigned.c ft_conver_hexa.c\

OBJS		= ${SRCS:.c=.o}

${NAME}	:
			${CC} -c ${CFLAGS} ${SRCS} 
			ar crs ${NAME} ${OBJS}

all		:	${NAME}

clean	:
		${RM} ${OBJS} 
	
fclean	:	clean
		${RM} -f ${NAME}

re		:	fclean all

.PHONY: all clean fclean re