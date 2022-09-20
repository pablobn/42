# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 09:04:28 by rauaguil          #+#    #+#              #
#    Updated: 2022/09/19 18:45:10 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rush-02
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
SRCSDIR		= ./src
OBJSDIR		= ./build
SRCS		= ${SRCSDIR}/main.c ${SRCSDIR}/dict.c ${SRCSDIR}/utils.c ${SRCSDIR}/string_utils.c ${SRCSDIR}/errors.c ${SRCSDIR}/ft_read_value.c ${SRCSDIR}/ft_itoa.c ${SRCSDIR}/string_utils_2.c ${SRCSDIR}/numbers_utils.c ${SRCSDIR}/numbers_utils_2.c
OBJS		= ${SRCS:.c=.o}

.c.o	:
	${CCOMP} ${CFLAGS} -c $< -o ${<:.c=.o} -Iincludes

${NAME}	:	${OBJS}
		${CCOMP} ${CFLAGS} -o ${NAME} ${OBJS}

clean	:
		${RM} ${OBJS}
	
fclean	:	clean
		${RM} ${NAME}

.PHONY: clean fclean .c.o