NAME = fragtrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXSTD = -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXSTD) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXSTD) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
re: fclean all