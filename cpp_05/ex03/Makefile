NAME = Bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp  main.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
OBJ = $(SRC:.cpp=.o)

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
