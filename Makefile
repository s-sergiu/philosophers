NAME = philo
CC = cc 
FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
OBJ_DIR = obj
INC = include/philosophers.h

all:$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	$(CC) $(FLAGS) $(OBJ) -o $@

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all

.PHONY:all clean fclean re
