NAME = intern
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp

HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
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