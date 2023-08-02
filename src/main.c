/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:35:37 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:34:55 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	render(game);
	free_game(game);
}
