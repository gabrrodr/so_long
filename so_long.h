/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:28:11 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/06/19 15:53:22 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "libft/libft.h"

typedef struct s_game
{
        char    **map;
        int     rows;
        int     cols;
        int     colectables;
        int     player;
        int     exit;
}       t_game;

void	free_map(char **map);
char	**create_map(char *str);
int	check(int c, int r, char **map);

#endif