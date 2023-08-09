/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:47:35 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/03 18:24:11 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_letters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
				&& game->map[y][x] != 'P' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'C')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	solong_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	moveability(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] == '0')
		return (0);
	if (game->map[y + 1][x] == '0')
		return (0);
	if (game->map[y][x + 1] == '0')
		return (0);
	if (game->map[y][x - 1] == '0')
		return (0);
	return (1);
}

void	enemy_position(t_game *game, int moves)
{
	int	enemies;
	int	position;

	position = 0;
	enemies = game->enemies;
	while (--enemies >= 0 && moves < game->moves)
	{
		while (moveability(game, game->enemy_x[enemies],
				game->enemy_y[enemies]))
		{
			enemies--;
			if (enemies < 0)
				return ;
		}
		position = game->enemy_x[enemies] + game->enemy_y[enemies];
		move_enemy(game, enemies);
		if (position == game->enemy_x[enemies] + game->enemy_y[enemies])
			enemies++;
	}
}

void	enemies_position(t_game *game)
{
	int	enemies;
	int	position;

	position = 0;
	enemies = game->enemies;
	while (--enemies >= 0)
	{
		while (moveability(game, game->enemy_x[enemies],
				game->enemy_y[enemies]))
		{
			enemies--;
			if (enemies < 0)
				return ; 
		}
		position = game->enemy_x[enemies] + game->enemy_y[enemies];
		move_enemy(game, enemies);
		if (position == game->enemy_x[enemies] + game->enemy_y[enemies])	
			enemies++;
	}
}
