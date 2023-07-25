/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:08:14 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/07/25 15:50:29 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    move_up_enemy(t_game *game, int enemies, int *y, int *x)
{
        if (game->map[y[enemies] - 1][x[enemies]] == '1' ||
                game->map[y[enemies] - 1][x[enemies]] == 'C' || 
                game->map[y[enemies] - 1][x[enemies]] == 'E' ||
                game->map[y[enemies] - 1][x[enemies]] == 'P')
        {
                return ;
        }
        game->map[y[enemies]][x[enemies]] = '0';
	walk_up_enemy(game, enemies);
}
