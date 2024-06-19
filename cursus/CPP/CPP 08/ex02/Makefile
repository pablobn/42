#PROGRAM NAME
NAME = convert

#COMPILATOR
CC = g++

#FLAGS
CFLAGS = -Werror -Wall -Wextra -std=c++98

#SOURCES
SRCSFD = src/
SRC = main.cpp

#OBJECTS
OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD), $(SRC:.cpp=.o))

#HEADERS
HDRSFD = includes/
HDR = MutantStack.hpp
HDRS = $(addprefix $(HDRSFD), $(HDR))
HDR_INC = -I./includes

#COLOURS
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m


all: ${NAME}

$(OBJSFD):
		@mkdir $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ directory"

${NAME}: $(OBJSFD) $(OBJS) $(HDRS)
		@$(CC) $(CFLAGS) $(OBJS) -o $@
		@echo "\t[ $(GREEN)✔$(NONE) ] $@ executable"
		
$(OBJSFD)%.o: $(SRCSFD)%.cpp
		@$(CC) $(CFLAGS) $(HDR_INC) -o $@ -c $<
clean: 
		@/bin/rm -rf $(OBJSFD)
		@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"

re:	fclean all

.PHONY: all clean fclean re 