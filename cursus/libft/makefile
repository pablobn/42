# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2022/09/30 19:34:30 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
SRCS		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c\
			  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
			  ft_strlcat.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
			  ft_substr.c ft_strjoin.c ft_strtrim.c
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