# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 15:17:39 by pbengoec          #+#    #+#              #
#    Updated: 2023/10/07 12:17:15 by pbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Werror -Wall -Wextra -g3
	
SRCSFD = src/

SOLONGPFD = so_long/
GNLPFD = get_next_line/

SOLONG_SRC = main.c start.c list_utils.c game.c map.c \
			image.c movements.c finish.c check_errors.c\
			flood_fill.c ft_check_figures.c create_position.c
GNLPFD_SRC = get_next_line.c get_next_line_utils.c

OBJSFD = objs/
SOLONG_OBJS = $(addprefix $(OBJSFD)$(SOLONGPFD), $(SOLONG_SRC:.c=.o))
GNL_OBJS = $(addprefix $(OBJSFD)$(GNLPFD), $(GNLPFD_SRC:.c=.o))

HDRSFD = includes/
HDR = so_long.h
HDRS = $(addprefix $(HDRSFD), $(HDR))

HDR_INC = -I./includes

LIBFT = library/libft/libft.a
MLX = ./library/MLX42/libmlx42.a
MLX_INC = -L "/Users/$$USER/.brew/opt/glfw/lib/" -I ./MLX42/include

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m


all: $(HDRS) ${NAME}

${MLX}:
		@make -C library/MLX42
	
${LIBFT}:
		@make -C library/libft

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(SOLONGPFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

$(OBJSFD)$(GNLPFD): $(OBJSFD)
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: ${MLX} ${LIBFT} $(OBJSFD)$(SOLONGPFD) $(OBJSFD)$(GNLPFD) ${GNL_OBJS} $(SOLONG_OBJS) $(HDRS)
		@gcc $(CFLAGS) $(SOLONG_OBJS) ${GNL_OBJS} $(MLX) ${LIBFT} -o $@  -lglfw ${MLX_INC}
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"
		
$(OBJSFD)$(SOLONGPFD)%.o: $(SRCSFD)$(SOLONGPFD)%.c $(HDRS)
		@gcc $(CFLAGS) $(HDR_INC) -o $@ -c $<

$(OBJSFD)$(GNLPFD)%.o: $(SRCSFD)$(GNLPFD)%.c
		@gcc $(CFLAGS) -o $@ -c $<


clean: 
		@/bin/rm -rf $(OBJSFD)
		@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
		@${MAKE} -s -C library/libft/ clean
		@${MAKE} -s -C library/MLX42/ clean

fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
		@${MAKE} -s -C library/libft/ fclean
		@${MAKE} -s -C library/MLX42/ fclean
	
re:	fclean all

.PHONY: check_libft check_minilibx project all clean fclean re 