NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Fixed.cpp main.cpp
HEADER = Fixed.hpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re