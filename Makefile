# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atruphem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 18:28:25 by atruphem          #+#    #+#              #
#    Updated: 2021/02/24 00:11:51 by atruphem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = ./libft/libft.a

OBJ =	$(addprefix srcs/, bmp.o color.o get_next_line_bonus.o playermoveb.o \
		raycaster.o testmapc.o clean.o cub3d.o get_next_line_utils_bonus.o \
		playerstart.o sprites.o textures.o clean2.o cubfilereader.o \
		parsmap.o print.o spritesb.o theend.o clean3.o divers.o \
		parsparam.o printsprites.o testmap.o utils.o cleanmem.o error.o \
		playermove.o printtextures.o testmapb.o)

CCFLAGS = -Wall -Werror -Wextra

LFLAGS = -L libft -lft

CC = clang

OS := $(shell uname -s)
ifeq ($(OS),Darwin)
	CCFLAGS += -D MACOS 
	LFLAGS += -L mlx -lmlx -framework OpenGL -framework AppKit -lz
	MLX = mlx
endif
ifeq ($(OS),Linux)
	LFLAGS += -L mlx-linux -lmlx -L /usr/lib -lXext -lX11 -lm
	MLX = mlx-linux
endif

LIBMLX = ./$(MLX)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) -o $@ $(OBJ) $(LFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< -I includes -I libft -I $(MLX) $(CCFLAGS)

$(LIBFT):
	make -C libft

$(LIBMLX):
	make -C $(MLX)

clean:
	make -C libft fclean
	make -C $(MLX) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
