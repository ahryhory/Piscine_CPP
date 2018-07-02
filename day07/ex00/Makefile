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
BIN = whatever
SRC = whatever.cpp
OBJ = $(SRC:.cpp=.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

whatever.o : whatever.cpp
	$(CC) $(CFLAGS) -c whatever.cpp -o whatever.o

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(BIN)

re: fclean all
