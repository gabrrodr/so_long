/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:37 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/06/19 15:11:18 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
        t_game  *game;

	if (argc != 2)
	{
		ft_printf("you need 2 arguments!\n");
		return (0);
	}
        game = init();
	game->map = create_map(argv[1]);
	check (game->cols, game->rows, game->map);
        free_map(game->map);
}
