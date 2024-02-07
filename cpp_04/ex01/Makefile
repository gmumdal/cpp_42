NAME = brain
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
INCS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
INC_DIR = -I ./
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
CPP = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^ $(INC_DIR)

$(OBJ_DIR)/%.o : %.cpp $(INCS)
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CFLAGS) -c -o $@ $< $(INC_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
