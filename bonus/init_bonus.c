/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:58:57 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:32:23 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	game->lives = 13;
	game->enemies = 0;
	game->enemy_x = NULL;
	game->enemy_y = NULL;
	game->initial.x = 0;
	game->initial.y = 0;
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
	game->tile.x = SIZE;
	game->tile.y = SIZE;
	init_game(game);
	init_img(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		return (NULL);
	}
	return (game);
}