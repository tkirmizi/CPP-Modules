NAME = phonebook
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXSTD = -std=c++11
CXXFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXSRD) $(CXXFLAGS) $(OBJS) -o $(NAME)
	$(RM) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXSTD) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
re: fclean all