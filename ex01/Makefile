NAME = form
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM) -f $(OBJS)
fclean: clean
	$(RM) -f $(NAME)
re: fclean all

.PHONY: all clean fclean re