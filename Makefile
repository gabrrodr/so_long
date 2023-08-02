# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 14:27:45 by gabrrodr          #+#    #+#              #
#    Updated: 2023/08/02 19:37:31 by gabrrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./minilibx -lm -lmlx -Ilmlx -lXext -lX11 -fsanitize=address
RM = rm -f

NAME = so_long
NAME_BNS = so_long_bonus

SRC = 	src/map.c \
	src/frees.c \
	src/main.c \
	src/init.c \
	src/check.c \
	src/render.c \
	src/utils.c \
	src/movement.c \
	src/walks.c \

BNS =	bonus/map_bonus.c \
	bonus/fress_bonus.c \
	bonus/main_bonus.c \
	bonus/init_bonus.c \
	bonus/check_bonus.c \
	bonus/render_bonus.c \
	bonus/utils_bonus.c \
	bonus/movement_bonus.c \
	bonus/walks_bonus.c \
	bonus/collect.c \
	bonus/enemies.c \
	bonus/move_enemies.c \
	bonus/walk_enemy.c \
	bonus/hurt.c \

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