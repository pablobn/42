# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 17:10:02 by pbengoec          #+#    #+#              #
#    Updated: 2023/05/23 15:42:30 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

PIPEXFD = pipex/

SRCSFD = src/
PIPEX_SRC = pipex.c \
				child.c \
				free.c \
				message.c

OBJSFD = objs/
PIPEX_OBJS = $(addprefix $(OBJSFD)$(PIPEXFD), $(PIPEX_SRC:.c=.o))

HDRSFD = includes/
HDR = pipex.h
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes
LIBFT_HDR = -I./library/libft/includes/
LIB_BINARY = -L./library/libft -lft
LIBFT = library/libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: ${NAME}

${LIBFT}:
	@make -C library/libft

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(PIPEXFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: ${LIBFT} ${OBJSFD}$(PIPEXFD) ${PIPEX_OBJS} $(LIBFT) $(HDRS)
	@gcc ${CFLAGS} $(LIB_BINARY) ${PIPEX_OBJS} -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

$(OBJSFD)$(PIPEXFD)%.o: $(SRCSFD)$(PIPEXFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<


clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@${MAKE} -s -C library/libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@${MAKE} -s -C library/libft/ fclean

re: fclean all

.PHONY: all clean fclean re