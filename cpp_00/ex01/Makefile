NAME = phonebook
SRCS = PhoneBook.cpp Contact.cpp main.cpp
INCS = PhoneBook.hpp Contact.hpp
INC_DIR = -I ./
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
CPP = g++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^ $(INC_DIR)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CPP) $(CFLAGS) -c -o $@ $< $(INC_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re