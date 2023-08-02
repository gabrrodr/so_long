/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:22:04 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/07/14 16:04:50 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    collect_down(t_game *game)
{
        put_tile(game, "./img/taytaygrab.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(40000);
        put_tile(game, "./img/taytaygrab1.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(40000);
        put_tile(game, "./img/taytaygrab2.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(40000);
        put_tile(game, "./img/taytaygrab1.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(120000);
        put_tile(game, "./img/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
}

void    collect_up(t_game *game)
{
        put_tile(game, "./img/taytaygrabB.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(40000);
        put_tile(game, "./img/taytaygrabB1.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(40000);
        put_tile(game, "./img/taytaygrabB2.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(40000);
        put_tile(game, "./img/taytaygrabB1.xpm", game->player.x * SIZE, game->player.y * SIZE);
        usleep(120000);
        put_tile(game, "./img/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
}