# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2022/10/05 20:51:09 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -f
SRCS		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_tolower.c ft_toupper.c\
			  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
			  ft_strlcat.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putendl_fd.c ft_putnbr_fd.c


BONUSSRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
			  ft_lstmap_bonus.c

OBJS		= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}	

${NAME}	:
			${CC} -c ${CFLAGS} ${SRCS} 
			ar crs ${NAME} ${OBJS}

bonus	:
			${CC} -c ${CFLAGS} ${SRCS} ${BONUSSRCS} 
			ar crs ${NAME} ${BONUSOBJS} ${OBJS}

all		:	${NAME}

clean	:
		${RM} ${OBJS} 
		${RM} -f ${BONUSOBJS}
	
fclean	:	clean
		${RM} -f ${NAME}

re		:	fclean all

.PHONY: all clean fclean re bonus