/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:10:56 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/07/14 13:49:38 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, char *img, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr,
            img, &game->tile.x, &game->tile.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
        game->img.mlx_img, x, y);
}

void	print_borders(t_game *game, int y, int x)
{
	if (y == 0 && x == 0)
		put_tile(game, "./img/cantosupesq.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x == (game->cols - 1))
		put_tile(game, "./img/cantosupdir.xpm", x * SIZE, y * SIZE);
	if (y == (game->rows - 1) && x == 0)
		put_tile(game, "./img/cantoinfesq.xpm", x * SIZE, y * SIZE);
	if (y == (game->rows - 1) && x == (game->cols - 1))
		put_tile(game, "./img/cantoinfdir.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x > 0 && x < (game->cols - 1))
		put_tile(game, "./img/wallup.xpm", x * SIZE, y * SIZE);
	if (y == (game->rows - 1) && x > 0 && x < (game->cols - 1))
		put_tile(game, "./img/walldown.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < (game->rows - 1) && x == 0)
		put_tile(game, "./img/wallleft.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < (game->rows - 1) && x == (game->cols - 1))
		put_tile(game, "./img/wallright.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < (game->rows - 1) && x > 0 && x < (game->cols - 1))
		put_tile(game, "./img/wall.xpm", x * SIZE, y * SIZE);
}

void	print_elements(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		put_tile(game, "./img/floor.xpm", x * SIZE, y * SIZE);
	if (game->map[y][x] == 'P')
		put_tile(game, "./img/taytay.xpm", x * SIZE, y * SIZE);
	if (game->map[y][x] == 'E')
		put_tile(game, "./img/exit.xpm", x * SIZE, y * SIZE);
	if (game->map[y][x] == 'C')
		put_tile(game, "./img/collectible1.xpm", x * SIZE, y * SIZE);
}

void	print_map(t_game *game)
{
	int	y;
	int	x;
	
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')			
				print_borders(game, y, x);
			if (game->map[y][x] != '1')
				print_elements(game, y, x);
		}
		
	}
	
}

void	render_window(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->cols * SIZE, game->rows * SIZE, "welcome!");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		return ;
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->cols * SIZE, game->rows * SIZE);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,
            &game->img.line_len, &game->img.endian);
}

void	render(t_game *game)
{
	render_window(game);
	if (!game->win_ptr)
	{
		return ;
	}
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &ft_quit, game);
	print_map(game);
	mlx_loop(game->mlx_ptr);
}