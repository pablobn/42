NAME = megaphone

CC = g++

CFLAGS = -Werror -Wall -Wextra -std=c++98

SRC = megaphone.cpp

OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD), $(SRC:.cpp=.o))

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m


all: ${NAME}

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: $(OBJSFD) $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"
		
$(OBJSFD)%.o: ${SRC}
		@$(CC) $(CFLAGS) -o $@ -c ${SRC}
clean: 
		@/bin/rm -rf $(OBJSFD)
		@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"

re:	fclean all

.PHONY: all clean fclean re 