/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:41:22 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 16:10:09 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long_bonus.h"


int    ft_quit(t_game *game)
{
        free_game(game);
        exit (1);
}

void    walk_up(t_game *game)
{
        int     tile;
        
        tile = game->player.y;
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        game->player.y -= 1;
        put_tile(game, "./img/taytayup1.xpm", game->player.x * SIZE, game->player.y * SIZE + ((SIZE / 3) * 2));
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytayup2.xpm", game->player.x * SIZE, game->player.y * SIZE + (SIZE / 3));
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytayback.xpm", game->player.x * SIZE, game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        //game->player.y = tile;
        //usleep(8000);
        game->moves++;
        render_moves(game);
        ft_printf("MOVES: %d\n", game->moves);
}

void    walk_down(t_game *game)
{
        int     tile;
        
        tile = game->player.y;
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        game->player.y += 1;
        put_tile(game, "./img/taytaydown1.xpm", game->player.x * SIZE, game->player.y * SIZE - ((SIZE / 3) * 2));
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytaydown2.xpm", game->player.x * SIZE, game->player.y * SIZE - (SIZE / 3));
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", game->player.x * SIZE, tile * SIZE);
        //game->player.y = tile;
        //usleep(8000);
        game->moves++;
        render_moves(game);
        ft_printf("MOVES: %d\n", game->moves);
}

void    walk_right(t_game *game)
{
        int     tile;
        
        tile = game->player.x;
        put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        game->player.x += 1;
        put_tile(game, "./img/taytayright1.xpm", game->player.x * SIZE - ((SIZE / 3) * 2), game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytayright2.xpm", game->player.x * SIZE - (SIZE / 3), game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        usleep(85000);
        put_tile(game, "./img/taytayright.xpm", game->player.x * SIZE, game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        //game->player.x = tile;
        //usleep(8000);
        game->moves++;
        render_moves(game);
        ft_printf("MOVES: %d\n", game->moves);
}

void    walk_left(t_game *game)
{
        int     tile;
        
        tile = game->player.x;
        put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        game->player.x -= 1;
        put_tile(game, "./img/taytayleft1.xpm", game->player.x * SIZE + ((SIZE / 3) * 2), game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", tile * SIZE , game->player.y * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytayleft2.xpm", game->player.x * SIZE + (SIZE / 3), game->player.y * SIZE);
        put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        usleep(95000);
        put_tile(game, "./img/taytayleft.xpm", game->player.x * SIZE, game->player.y * SIZE);
	put_tile(game, "./img/floor.xpm", tile * SIZE, game->player.y * SIZE);
        //game->player.x = tile;
        //usleep(8000);
        game->moves++;
        render_moves(game);
        ft_printf("MOVES: %d\n", game->moves);
}