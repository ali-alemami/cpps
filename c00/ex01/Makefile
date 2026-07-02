NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Contact.hpp PhoneBook.hpp

%.o: %.cpp $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re