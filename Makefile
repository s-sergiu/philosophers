NAME = philo
CC = cc 
FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
OBJ_DIR = obj

all:$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

$(OBJ): $(SRC)
	$(CC) -c $(OUTPUT_OPTION) $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all

.PHONY:all clean fclean re
