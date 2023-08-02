/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:37 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:46:35 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_file(char *str)
{
	int	fd;
	char	*ber;

	ber = ".ber";
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error. can't open file\n");
		close(fd);
		return (1);
	}
	str = ft_strrchr(str, '.');
	if (!str)
	{
		ft_printf("Error. Invalid\n");
		return (1);
	}
	if (ft_strncmp(str, ber, 4) != 0)
	{
		ft_printf("Error. Invalid\n");
		return (1);
	}
	close(fd);
	return (0);
}

void	render_moves(t_game *game)
{
	char	*moves;
	char	*lives;
	int	x;
	int	y;
	
	x = game->cols / 2;
	y = game->rows;
	put_tile(game, "./textures/black.xpm", x * SIZE, y * SIZE);
	put_tile(game, "./textures/black.xpm", (x + 1) * SIZE, y * SIZE);
	put_tile(game, "./textures/black.xpm", 1 * SIZE, y * SIZE);
	moves = ft_itoa(game->moves);
	lives = ft_itoa(game->lives);
	x = (game->cols / 2) * SIZE;
	y = game->rows * SIZE + 32;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0x0000FF00, moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 1 * SIZE, y, 0xFF0000, "LIVES: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, SIZE + 42, y, 0xFFFFFF, lives);
	free (moves);
	free (lives);
}

int	main(int argc, char **argv)
{
        t_game  *game;

	if (argc != 2 || check_file(argv[1]) != 0)
	{
		ft_printf("you need 2 arguments!\n");
		return (0);
	}
        game = init();
	if (!game)
	{
		free_game(game);
		return (1);
	}
	check_map(argv[1], game);
	if (!game->map || game->valid != 0)
	{
		free_game(game);
		return (1);
	}
	if (init_enemy(game))
	{
		free_game(game);
		return (1);
	}
	render(game);
	free_game(game);
	return (0);
}
