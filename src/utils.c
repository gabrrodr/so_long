/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:47:35 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:35:25 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_letters(t_game *game)
{
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' && 
				game->map[y][x] != 'P' && game->map[y][x] != 'E' &&
				game->map[y][x] != 'C')
			{
				return (1);
			}
			x++;
		}	
		x = 0;
		y++;
	}
	return (0);
}

int	solong_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}