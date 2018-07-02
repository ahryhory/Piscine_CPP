# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlinkin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 11:19:45 by dlinkin           #+#    #+#              #
#    Updated: 2018/06/23 11:19:46 by dlinkin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I./includes/
NCUR = -lncurses
BIN = ft_retro
SRC_DIR = ./src/
SRC_PATH =	main.cpp\
			Game.cpp\
			AWindow.cpp\
			Menu.cpp\
			Scene.cpp\
			Ship.cpp\
			Object.cpp\
			Projectile.cpp\
			Enemy.cpp\
			Boss.cpp
SRC = $(addprefix $(SRC_DIR),$(SRC_PATH))
OBJ_DIR = ./obj/
OBJ_PATH = $(SRC_PATH:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_PATH))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(NCUR) -o $(BIN)

obj/main.o : src/main.cpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/main.cpp -o obj/main.o

obj/Game.o : src/Game.cpp includes/Game.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Game.cpp -o obj/Game.o

obj/AWindow.o : src/AWindow.cpp includes/AWindow.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/AWindow.cpp -o obj/AWindow.o

obj/Scene.o : src/Scene.cpp includes/Scene.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Scene.cpp -o obj/Scene.o

obj/Menu.o : src/Menu.cpp includes/Menu.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Menu.cpp -o obj/Menu.o

obj/Ship.o : src/Ship.cpp includes/Ship.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Ship.cpp -o obj/Ship.o

obj/Object.o : src/Object.cpp includes/Object.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Object.cpp -o obj/Object.o

obj/Projectile.o : src/Projectile.cpp includes/Projectile.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Projectile.cpp -o obj/Projectile.o

obj/Enemy.o : src/Enemy.cpp includes/Enemy.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Enemy.cpp -o obj/Enemy.o

obj/Boss.o : src/Boss.cpp includes/Boss.hpp includes/ft_retro.h
	$(CC) $(CFLAGS) -c src/Boss.cpp -o obj/Boss.o

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(BIN)

re: fclean all

run:
	./ft_retro
