# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2022/09/21 20:41:45 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
SRCS		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c
OBJS		= ${SRCS:.c=.o}

${NAME}	:
			${CC} -c ${CFLAGS} ${SRCS} 
			ar crs ${NAME} ${OBJS}

all		:	${NAME}

clean	:
		${RM} ${OBJS}
	
fclean	:	clean
		${RM} ${NAME}

re		:	fclean all

.PHONY: all clean fclean re