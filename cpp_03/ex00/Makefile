NAME = claptrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp  main.cpp
OBJ = $(SRC:.cpp=.o)

HEADERS = ClapTrap.hpp

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