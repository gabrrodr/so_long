# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 14:27:45 by gabrrodr          #+#    #+#              #
#    Updated: 2023/07/27 19:08:58 by gabrrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = so_long
NAME_BNS = so_long_bonus

SRC = 	map.c \
	frees.c \
	main.c \
	init.c \
	check.c \
	render.c \
	utils.c \
	movement.c \
	walks.c \

BNS =	map_bonus.c \
	fress_bonus.c \
	main_bonus.c \
	init_bonus.c \
	check_bonus.c \
	render_bonus.c \
	utils_bonus.c \
	movement_bonus.c \
	walks_bonus.c \
	collect.c \
	enemies.c \
	move_enemies.c \
	walk_enemy.c \
	moves_lives.c \
	hurt.c \

OBJ_SRC = $(SRC:.c=.o)
OBJ_BNS = $(BNS:.c=.o)


LIBFT = libft/libft.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx

$(NAME): $(OBJ_SRC) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BNS)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./minilibx
	@$(RM) $(OBJ_SRC) $(OBJ_BNS)

fclean: clean
	@$(RM) $(LIBFT) $(NAME) $(NAME_BNS)
	
re: fclean all