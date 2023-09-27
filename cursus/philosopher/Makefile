# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 17:10:02 by pbengoec          #+#    #+#              #
#    Updated: 2023/09/27 16:27:38 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -fsanitize=thread -g -pthread -Wall -Wextra -Werror

PHILOFD = philo/

SRCSFD = src/
PHILO_SRC = philo.c \
			free.c

OBJSFD = objs/
PHILO_OBJ = $(addprefix $(OBJSFD)$(PHILOFD), $(PHILO_SRC:.c=.o))

HDRSFD = includes/
HDR = philo.h
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes

# LIBFT INCLUDES
LIBFT_HDR = -I./library/libft/includes/
LIB_BINARY = -L./library/libft -lft
LIBFT = library/libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

all: ${HDRS} ${NAME}

${LIBFT}:
	@make -C library/libft

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(PHILOFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: ${LIBFT} ${OBJSFD}$(PHILOFD) ${PHILO_OBJ}  $(HDRS)
	@gcc ${CFLAGS} $(LIB_BINARY) ${PHILO_OBJ} -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

$(OBJSFD)$(PHILOFD)%.o: $(SRCSFD)$(PHILOFD)%.c $(HDRS) 
	@gcc $(CFLAGS) $(HDR_INC) ${LIBFT_HDR} -o $@ -c $< 

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