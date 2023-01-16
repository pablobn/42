# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:45:05 by pbengoec          #+#    #+#              #
#    Updated: 2023/01/13 15:52:36 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CFLAGS = -Werror -Wall -Wextra

PUSHSWAPFD = push_swap/

SRCSFD = src/
PUSHSWAP_SRC = main.c \
					ft_push_swap.c\
					ft_list_utils.c\
					ft_list_utils_2.c\
					ft_list_utils_3.c\
					ft_list_utils_4.c\
					ft_list_utils_5.c

OBJSFD = objs/
PUSHSWAP_OBJS = $(addprefix $(OBJSFD)$(PUSHSWAPFD), $(PUSHSWAP_SRC:.c=.o))

HDRSFD = includes/
HDR = push_swap.h
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes
LIBFT_HRD = -I./libft/includes/
LIB_BINARY = -L./libft -lft
LIBFT = libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m


all: check_libft project $(HDRS) ${NAME}
		@echo "Project ready"

check_libft:
		@echo "Checking libft..."
		@make -C libft

project:
		@echo "Checking project..."

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(PUSHSWAPFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: $(OBJSFD)$(PUSHSWAPFD) $(PUSHSWAP_OBJS) $(LIBFT) $(HDRS)
		@gcc $(CFLAGS) $(LIB_BINARY) $(PUSHSWAP_OBJS) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"
		
$(OBJSFD)$(PUSHSWAPFD)%.o: $(SRCSFD)$(PUSHSWAPFD)%.c $(HDRS) $(LIBFD)
		@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<

clean: 
		@/bin/rm -rf $(OBJSFD)
		@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
		@${MAKE} -C libft/ clean

fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
		@${MAKE} -C libft/ fclean
	
re:	fclean all

.PHONY: check_libft project all clean fclean re 