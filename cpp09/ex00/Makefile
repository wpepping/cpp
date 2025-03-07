SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.obj)
NAME = btc
HEADERS = BitcoinExchange.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(OBJS) -o $(NAME)

%.obj: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re debug
