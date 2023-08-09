/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:22:04 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/03 16:44:48 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	collect_down(t_game *game)
{
	put_tile(game, "./textures/taytaygrab.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(40000);
	put_tile(game, "./textures/taytaygrab1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(40000);
	put_tile(game, "./textures/taytaygrab2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(40000);
	put_tile(game, "./textures/taytaygrab1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(120000);
	put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
}

void	collect_up(t_game *game)
{
	put_tile(game, "./textures/taytaygrabB.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(40000);
	put_tile(game, "./textures/taytaygrabB1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(40000);
	put_tile(game, "./textures/taytaygrabB2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(40000);
	put_tile(game, "./textures/taytaygrabB1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(120000);
	put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
}
