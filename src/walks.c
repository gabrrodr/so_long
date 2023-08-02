/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:41:22 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 18:20:22 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/so_long.h"


int    ft_quit(t_game *game)
{
        free_game(game);
        exit (1);
}

void    walk_up(t_game *game)
{
        int     tile;
        
        tile = game->player.y;
        put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, tile * SIZE);
        game->player.y -= 1;
        put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
        game->moves++;
        ft_printf("MOVES: %d\n", game->moves);
}

void    walk_down(t_game *game)
{
        int     tile;
        
        tile = game->player.y;
        put_tile(game, "./textures/floor.xpm", game->player.x * SIZE, tile * SIZE);
        game->player.y += 1;
        put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
        game->moves++;
        ft_printf("MOVES: %d\n", game->moves);
}

void    walk_right(t_game *game)
{
        int     tile;
        
        tile = game->player.x;
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->player.y * SIZE);
        game->player.x += 1;
        put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
        game->moves++;
        ft_printf("MOVES: %d\n", game->moves);
}

void    walk_left(t_game *game)
{
        int     tile;
        
        tile = game->player.x;
        put_tile(game, "./textures/floor.xpm", tile * SIZE, game->player.y * SIZE);
        game->player.x -= 1;
        put_tile(game, "./textures/taytay.xpm", game->player.x * SIZE, game->player.y * SIZE);
        game->moves++;
        ft_printf("MOVES: %d\n", game->moves);
}