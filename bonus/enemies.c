/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:15:13 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 17:45:23 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int    	count_floor(t_game *game)
{
	int	x;
	int	y;
	int	t;
	
	t = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				t++;
		}
	}
	return (t);
}

int	validate_enemies(t_game *game)
{
	if (!game->enemy_y || !game->enemy_x)
	{
		if (game->enemy_y)
			free(game->enemy_y);
		if (game->enemy_x)
			free(game->enemy_x);
		return (1);
	}
	return (0);
}

int	init_enemy(t_game *game)
{
	int	y;
	int	x;
	int	enemies;
	
	game->enemies = count_floor(game) / 20;
	game->enemy_x = ft_calloc(game->enemies, sizeof(int));
	game->enemy_y = ft_calloc(game->enemies, sizeof(int));
	enemies = game->enemies;
	if (validate_enemies(game))
		return (1);
	while (--enemies >= 0)
	{
		y = 0;
		x = 0;
		while (game->map[y][x] != '0')
		{
			y = rand() % (game->rows - 1);
			x = rand() % (game->cols - 1);
		}
		game->enemy_y[enemies] = y;
		game->enemy_x[enemies] = x;
	}
	return (0);
}

void    render_enemies(t_game *game)
{
        int     e;
        
        e = -1;
        while (++e < game->enemies)
        {
                put_tile(game, "./img/scooter1.xpm", game->enemy_x[e] * SIZE, game->enemy_y[e] * SIZE);
		game->map[game->enemy_y[e]][game->enemy_x[e]] = 'S';
        }
}
