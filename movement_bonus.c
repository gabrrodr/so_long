/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:30:53 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/07/25 16:37:50 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void    move_down(t_game *game)
{
        t_point p;
        
        p = game->player;
        if (game->map[p.y + 1][p.x] == '1' ||
                (game->map[p.y + 1][p.x] == 'E' && game->gathered != game->colectables))
        {
                return ;
        }
        if (game->map[p.y + 1][p.x] == 'E' && game->gathered == game->colectables)
        {
                walk_down(game);
                ft_printf("YOU GOT THE GRAMMY TAYTAY\n");
                ft_quit(game);
                return ;
        }
        if (game->map[p.y + 1][p.x] == 'C')
        {
                walk_down(game);
                collect_down(game);
                game->gathered++;
                game->map[p.y + 1][p.x] = '0';
        }
        else
                walk_down(game);
}

void    move_up(t_game *game)
{
        t_point p;
        
        p = game->player;
        if (game->map[p.y - 1][p.x] == '1' ||
                (game->map[p.y - 1][p.x] == 'E' && game->gathered != game->colectables))
        {
                return ;
        }
        if (game->map[p.y - 1][p.x] == 'E' && game->gathered == game->colectables)
        {
                walk_up(game);
                ft_printf("YOU GOT THE GRAMMY TAYTAY\n");
                ft_quit(game);
                return ;
        }
        if (game->map[p.y - 1][p.x] == 'C')
        {
                walk_up(game);
                collect_up(game);
                game->gathered++;
                game->map[p.y - 1][p.x] = '0';
                
        }
        else
                walk_up(game);
}

void    move_right(t_game *game)
{
        t_point p;
        
        p = game->player;
        if (game->map[p.y][p.x + 1] == '1' ||
                (game->map[p.y][p.x + 1] == 'E' && game->gathered != game->colectables))
        {
                return ;
        }
        if (game->map[p.y][p.x + 1] == 'E' && game->gathered == game->colectables)
        {
                walk_right(game);
                ft_printf("YOU GOT THE GRAMMY TAYTAY\n");
                ft_quit(game);
                return ;
        }
        if (game->map[p.y][p.x + 1] == 'C')
        {
                walk_right(game);
                collect_down(game);
                game->gathered++;
                game->map[p.y][p.x + 1] = '0';
        }
        else
                walk_right(game);
}

void    move_left(t_game *game)
{
        t_point p;
        
        p = game->player;
        if (game->map[p.y][p.x - 1] == '1' ||
                (game->map[p.y][p.x - 1] == 'E' && game->gathered != game->colectables))
        {
                return ;
        }
        if (game->map[p.y][p.x - 1] == 'E' && game->gathered == game->colectables)
        {
                walk_left(game);
                ft_printf("YOU GOT THE GRAMMY TAYTAY\n");
                ft_quit(game);
        }
        if (game->map[p.y][p.x - 1] == 'C')
        {
                walk_left(game);
                collect_down(game);
                game->gathered++;
                game->map[p.y][p.x - 1] = '0';
        }
        else
                walk_left(game);
}

int     handle_keypress(int keysym, t_game *game)
{
        int     moves;

        moves = game->moves;
        if (keysym == XK_Escape)
                ft_quit(game);
        if (keysym == XK_Up || keysym == XK_w)
                move_up(game);
        if (keysym == XK_Down || keysym == XK_s)
                move_down(game);
        if (keysym == XK_Right || keysym == XK_d)
                move_right(game);
        if (keysym == XK_Left || keysym == XK_a)
                move_left(game);
        enemy_position(game);
        return (0);
}