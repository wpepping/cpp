SRCS = main.cpp ScalarConverter.cpp ScalarConverterFormats.cpp
OBJS = $(SRCS:.cpp=.obj)
NAME = convert
HEADERS = ScalarConverter.hpp ScalarConverterFormats.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.obj: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
