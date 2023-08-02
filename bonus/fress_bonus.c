/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fress_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:06 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 19:32:28 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
	{
		return ;
	}
	while (map[i])
		free(map[i++]);
	free(map);
}
void	free_game(t_game *game)
{
	if(!game)
		return ;
	if (game->map)
	{
		free_map(game->map);
	}	
	if(game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if(game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->enemy_x)
		free(game->enemy_x);
	if (game->enemy_y)
		free(game->enemy_y);
	free(game);
}