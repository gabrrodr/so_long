/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:10:56 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/03 16:37:23 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_borders(t_game *game, int y, int x)
{
	if (y == 0 && x == 0)
		put_tile(game, "./textures/cantosupesq.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x == (game->cols - 1))
		put_tile(game, "./textures/cantosupdir.xpm", x * SIZE, y * SIZE);
	if (y == (game->rows - 1) && x == 0)
		put_tile(game, "./textures/cantoinfesq.xpm", x * SIZE, y * SIZE);
	if (y == (game->rows - 1) && x == (game->cols - 1))
		put_tile(game, "./textures/cantoinfdir.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x > 0 && x < (game->cols - 1))
		put_tile(game, "./textures/wallup.xpm", x * SIZE, y * SIZE);
	if (y == (game->rows - 1) && x > 0 && x < (game->cols - 1))
		put_tile(game, "./textures/walldown.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < (game->rows - 1) && x == 0)
		put_tile(game, "./textures/wallleft.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < (game->rows - 1) && x == (game->cols - 1))
		put_tile(game, "./textures/wallright.xpm", x * SIZE, y * SIZE);
	if (y > 0 && y < (game->rows - 1) && x > 0 && x < (game->cols - 1))
		put_tile(game, "./textures/wall.xpm", x * SIZE, y * SIZE);
}

void	print_elements(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		put_tile(game, "./textures/floor.xpm", x * SIZE, y * SIZE);
	if (game->map[y][x] == 'P')
		put_tile(game, "./textures/taytay.xpm", x * SIZE, y * SIZE);
	if (game->map[y][x] == 'E')
		put_tile(game, "./textures/exit.xpm", x * SIZE, y * SIZE);
	if (game->map[y][x] == 'C')
		put_tile(game, "./textures/collectible1.xpm", x * SIZE, y * SIZE);
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
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->cols * SIZE, game->rows
			* SIZE, "welcome!");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		return ;
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, game->cols * SIZE,
			game->rows * SIZE);
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
