# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 17:10:02 by pbengoec          #+#    #+#              #
#    Updated: 2023/10/05 17:46:26 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS =  -g -fsanitize=address -pthread -Wall -Wextra -Werror

PHILOFD = philo/

SRCSFD = src/
PHILO_SRC = philo.c   \
			free.c    \
			threads.c \
			utils.c   \
			status.c  \
			supervisor.c \
			utils_libft.c

OBJSFD = objs/
PHILO_OBJ = $(addprefix $(OBJSFD)$(PHILOFD), $(PHILO_SRC:.c=.o))

HDRSFD = includes/
HDR = philo.h
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes

#COLORES
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

all: ${HDRS} ${NAME}

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(PHILOFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: ${OBJSFD}$(PHILOFD) ${PHILO_OBJ}  $(HDRS)
	@gcc ${CFLAGS} ${PHILO_OBJ} -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"

$(OBJSFD)$(PHILOFD)%.o: $(SRCSFD)$(PHILOFD)%.c $(HDRS) 
	@gcc $(CFLAGS) $(HDR_INC) -o $@ -c $< 

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"

re: fclean all

.PHONY: all clean fclean re