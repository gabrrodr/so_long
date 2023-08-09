/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hurt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:55:59 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/03 17:15:06 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_tile(t_game *game, char *img, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, img, &game->tile.x,
			&game->tile.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, x,
		y);
}

void	hurt_player(t_game *game)
{
	put_tile(game, "./textures/taytaygrab.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytaygrab1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytaygrab2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytaylose.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(80000);
	put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	game->lives--;
}

void	hurt(t_game *game)
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
	put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, game->player.y
		* SIZE);
	game->map[game->initial.y][game->initial.x] = 'P';
	game->player.y = game->initial.y;
	game->player.x = game->initial.x;
	hurt_player(game);
}

void	kill_player(t_game *game)
{
	put_tile(game, "./textures/taytaylose.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(800000);
	put_tile(game, "./textures/taytaydie.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(900000);
	put_tile(game, "./textures/taytaydie.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	printf("💀💀GAME OVER💀💀\n");
	usleep(900000);
	ft_quit(game);
}
