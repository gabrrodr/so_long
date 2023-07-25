/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:58:57 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/07/24 14:06:52 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_img(t_game *game)
{
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
}

void	init_game(t_game *game)
{
	game->rows = 0;
	game->cols = 0;
	game->colectables = 0;
	game->rotation = 1;
	game->gathered = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->map = NULL;
	game->win_ptr = NULL;
	game->mlx_ptr = NULL;
	game->moves = 0;
	game->valid = 0;
	game->enemies = 0;
	game->enemy_x = NULL;
	game->enemy_y = NULL;
}

t_game	*init(void)
{
	t_game	*game;
	
	srand(time(NULL));
	game = malloc(sizeof(t_game));
	if(!game)
	{
		return (NULL);
	}
	game->tile.x = 64;
	game->tile.y = 64;
	init_img(game);
	init_game(game);
	game->mlx_ptr = mlx_init();
	return (game);
}