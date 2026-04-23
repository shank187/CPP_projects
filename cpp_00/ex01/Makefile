NAME = PhoneBook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp
HEADERS = PhoneBook.hpp Contact.hpp

OBJ = $(SRC:.cpp=.o)

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

