/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:08:14 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:32:17 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    move_up_enemy(t_game *game, int enemies, int *y, int *x)
{
        if (game->map[y[enemies] - 1][x[enemies]] == '1' ||
                game->map[y[enemies] - 1][x[enemies]] == 'C' || 
                game->map[y[enemies] - 1][x[enemies]] == 'E' ||
                game->map[y[enemies] - 1][x[enemies]] == 'S')
        {
                return ;
        }
        game->map[y[enemies]][x[enemies]] = '0';
	walk_up_enemy(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'S';
}

void    move_down_enemy(t_game *game, int enemies, int *y, int *x)
{
        if (game->map[y[enemies] + 1][x[enemies]] == '1' ||
                game->map[y[enemies] + 1][x[enemies]] == 'C' || 
                game->map[y[enemies] + 1][x[enemies]] == 'E' ||
                game->map[y[enemies] + 1][x[enemies]] == 'S')
        {
                return ;
        }
        game->map[y[enemies]][x[enemies]] = '0';
	walk_down_enemy(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'S';
}

void    move_right_enemy(t_game *game, int enemies, int *y, int *x)
{
        if (game->map[y[enemies]][x[enemies] + 1] == '1' ||
                game->map[y[enemies]][x[enemies] + 1] == 'C' || 
                game->map[y[enemies]][x[enemies] + 1] == 'E' ||
                game->map[y[enemies]][x[enemies] + 1] == 'S')
        {
                return ;
        }
        game->map[y[enemies]][x[enemies]] = '0';
	walk_right_enemy(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'S';
}

void    move_left_enemy(t_game *game, int enemies, int *y, int *x)
{
        if (game->map[y[enemies]][x[enemies] - 1] == '1' ||
                game->map[y[enemies]][x[enemies] - 1] == 'C' || 
                game->map[y[enemies]][x[enemies] - 1] == 'E' ||
                game->map[y[enemies]][x[enemies] - 1] == 'S')
        {
                return ;
        }
        game->map[y[enemies]][x[enemies]] = '0';
	walk_left_enemy(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'S';
}

void	move_enemy(t_game *game, int enemies)
{
	int	*x;
	int	*y;
	int	n;
	
	x = game->enemy_x;
	y = game->enemy_y;
	n = (rand() % 4) + 1;
	if (n == 1)
		move_up_enemy(game, enemies, y, x);
	if (n == 2)
		move_down_enemy(game, enemies, y, x);
	if (n == 3)
		move_right_enemy(game, enemies, y, x);
	if (n == 4)
		move_left_enemy(game, enemies, y, x);
        if (x[enemies] == game->player.x && y[enemies] == game->player.y)
		hurt(game);
}