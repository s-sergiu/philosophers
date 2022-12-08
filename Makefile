NAME=philo
CC = cc 
FLAGS = -Wall -Werror -Wextra

SRC_DIR= $(wildcard src/*.c)
OBJ = $(patsubst %.c,%.o,$(SRC_DIR))

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all
