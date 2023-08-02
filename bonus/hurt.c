/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hurt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:55:59 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:46:08 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	hurt_player(t_game *game)
{
	put_tile(game, "./textures/taytaygrab.xpm", game->player.x * SIZE, game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytaygrab1.xpm", game->player.x * SIZE, game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytaygrab2.xpm", game->player.x * SIZE, game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytaylose.xpm", game->player.x * SIZE, game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
	game->lives--;
}

void    hurt(t_game *game)
{
        if (game->lives == 1)
	{
		kill_player(game);
	}
        while (game->map[game->initial.y][game->initial.x] == 'S')
        {
                enemies_position(game);
        }
        game->map[game->player.y][game->player.x] = '0';
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, game->player.y * SIZE);
        game->map[game->initial.y][game->initial.x] = 'P';
        game->player.y = game->initial.y;
        game->player.x = game->initial.x;
        hurt_player(game);
}

void	kill_player(t_game *game)
{
	put_tile(game, "./textures/taytaylose.xpm", game->player.x * SIZE, game->player.y * SIZE);
	usleep(800000);
	put_tile(game, "./textures/taytaydie.xpm", game->player.x * SIZE, game->player.y * SIZE);
	usleep(900000);
	put_tile(game, "./textures/taytaydie.xpm", game->player.x * SIZE, game->player.y * SIZE);
	//exit_animation(game);
	printf("💀💀GAME OVER💀💀\n");
	usleep(900000);
	ft_quit(game);
	
}