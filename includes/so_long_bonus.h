/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:28:11 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 16:11:53 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>
# include "minilibx/mlx.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define SIZE 64

typedef struct s_point
{
        int	x;
        int	y;
}	t_point;

typedef struct s_collectible
{
        char    *collectible;
        char    *image_path;
}       t_collectible;

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_game
{
        void    *mlx_ptr;
        void    *win_ptr;
	char	**map;
        int	rows;
        int	cols;
        int	colectables;
        int     rotation;
        int     gathered;
        int     moves;
        int     valid;
        int     lives;
        int     enemies;
        int     *enemy_y;
        int     *enemy_x;
        t_point initial;
        t_point tile;
        t_point	player;
        t_point exit;
        t_img   img;
}       t_game;

void	free_map(char **map);
char	**create_map(char *str);
int	check_map(char *str, t_game *game);
int	check_rectangular(t_game *game);
int	count_r_c(t_game *game);
int	solong_strlen(char *str);
t_game	*init(void);
void	fill(char **map_copy, t_game *game, int x, int y);
void	render(t_game *game);
void	free_game(t_game *game);
int     handle_keypress(int keysym, t_game *game);
int     ft_quit(t_game *game);
void	put_tile(t_game *game, char *img, int x, int y);
int	check_letters(t_game *game);
void	render_moves(t_game *game);



//walks
void    walk_up(t_game *game);
void    walk_down(t_game *game);
void    walk_right(t_game *game);
void    walk_left(t_game *game);

//collects
void    collect_down(t_game *game);
void    collect_up(t_game *game);

//enemies
void    render_enemies(t_game *game);
int	init_enemy(t_game *game);
void	enemy_position(t_game *game, int moves);
void	enemies_position(t_game *game);
void	move_enemy(t_game *game, int enemies);
void	hurt_player(t_game *game);
void    hurt(t_game *game);

//walks enemies
void    walk_up_enemy(t_game *game, int enemies);
void    walk_down_enemy(t_game *game, int enemies);
void    walk_right_enemy(t_game *game, int enemies);
void    walk_left_enemy(t_game *game, int enemies);
void	kill_player(t_game *game);


#endif