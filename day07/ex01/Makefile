# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 14:45:12 by ahryhory          #+#    #+#              #
#    Updated: 2018/06/27 14:45:14 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I.
BIN = iter
SRC = iter.cpp
OBJ = $(SRC:.cpp=.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

iter.o : iter.cpp
	$(CC) $(CFLAGS) -c iter.cpp -o iter.o

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(BIN)

re: fclean all
