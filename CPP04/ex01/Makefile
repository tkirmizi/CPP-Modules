NAME = brain
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXSTD = -std=c++11
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