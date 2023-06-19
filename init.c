/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:58:57 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/06/19 15:08:00 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init(void)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if(!game)
	{
		return (NULL);
	}
	game->rows = 0;
	game->cols = 0;
	game->colectables = 0;
	game->player = 0;
	game->exit = 0;
	game->map = NULL;
	return (game);
}