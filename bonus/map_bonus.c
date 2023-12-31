/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:39:22 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/03 17:23:40 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_exit(t_game *game)
{
	int	x;
	int	y;
	int	exit;

	x = 0;
	y = 0;
	exit = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->exit.y = y;
				game->exit.x = x;
				exit++;
			}
			x++;
		}
		y++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

static int	check_p_c(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
				game->p++;
				game->initial.y = y;
				game->initial.x = x;
			}
			else if (game->map[y][x] == 'C')
				game->colectables++;
		}
	}
	if (game->p != 1 || game->colectables <= 0)
		return (1);
	return (0);
}

static int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\n' && y == 0)
		{
			if (!(game->map[0][x] == '1') || 
					!(game->map[game->rows - 1][x] == '1'))
			{
				return (1);
			}
			x++;
		}
		if (!(game->map[y][0] == '1') || !(game->map[y][game->cols - 1] == '1'))
		{
			return (1);
		}
		y++;
	}
	return (0);
}

static int	path_check(char *str, t_game *game)
{
	char	**map_copy;

	map_copy = create_map(str);
	if (!map_copy)
		return (1);
	fill(map_copy, game, game->player.x, game->player.y);
	if (!game->exit.y || !game->exit.x)
	{
		free_map(map_copy);
		return (1);
	}
	if (map_copy[game->exit.y][game->exit.x] != 'F')
	{
		free_map(map_copy);
		return (1);
	}
	if (game->colectables != game->gathered)
	{
		free_map(map_copy);
		return (1);
	}
	game->gathered = 0;
	free_map(map_copy);
	return (0);
}

int	check_map(char *str, t_game *game)
{
	int	check;

	check = 0;
	game->map = create_map(str);
	if (!game->map)
	{
		ft_printf("Invalid Map\n");
		return (1);
	}
	check = count_r_c(game) + check_rectangular(game) + check_exit(game)
		+ check_p_c(game);
	check += check_walls(game);
	check += check_letters(game);
	if (check == 0)
		check += path_check(str, game);
	if (check != 0)
	{
		ft_printf("Error: Invalid map\n");
		game->valid++;
		return (1);
	}
	return (0);
}
