NAME = interface

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AMateria.cpp  Character.cpp  MateriaSource.cpp  cure.cpp  Ice.cpp  main.cpp
OBJ = $(SRC:.cpp=.o)

HEADERS = AMateria.hpp  Character.hpp  Cure.hpp  ICharacter.hpp  IMateriaSource.hpp  Ice.hpp  MateriaSource.hpp

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