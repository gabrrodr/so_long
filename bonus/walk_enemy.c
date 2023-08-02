/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:48:28 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:47:56 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    walk_up_enemy(t_game *game, int enemies)
{
        int     tile;
        
        tile = game->enemy_y[enemies];
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
        game->enemy_y[enemies] -= 1;
        put_tile(game, "./textures/scooter2.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE + ((SIZE / 3) * 2));
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter3.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE + (SIZE / 3));
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter1.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
}

void    walk_down_enemy(t_game *game, int enemies)
{
        int     tile;
        
        tile = game->enemy_y[enemies];
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
        game->enemy_y[enemies] += 1;
        put_tile(game, "./textures/scooter2.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE - ((SIZE / 3) * 2));
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter3.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE - (SIZE / 3));
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter1.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", game->enemy_x[enemies] * SIZE, tile * SIZE);
}

void    walk_right_enemy(t_game *game, int enemies)
{
        int     tile;
        
        tile = game->enemy_x[enemies];
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
        game->enemy_x[enemies] += 1;
        put_tile(game, "./textures/scooter2.xpm", game->enemy_x[enemies] * SIZE - ((SIZE / 3) * 2), game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter3.xpm", game->enemy_x[enemies] * SIZE - (SIZE / 3), game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter1.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
}

void    walk_left_enemy(t_game *game, int enemies)
{
        int     tile;
        
        tile = game->enemy_x[enemies];
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
        game->enemy_x[enemies] -= 1;
        put_tile(game, "./textures/scooter2.xpm", game->enemy_x[enemies] * SIZE + ((SIZE / 3) * 2), game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter3.xpm", game->enemy_x[enemies] * SIZE + (SIZE / 3), game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
        usleep(30000);
        put_tile(game, "./textures/scooter1.xpm", game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->enemy_y[enemies] * SIZE);
}