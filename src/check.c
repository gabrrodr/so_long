/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:43:20 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/02 18:17:48 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (solong_strlen(game->map[0]) != solong_strlen(game->map[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_r_c(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while(game->map[rows] != NULL)
		rows++;
	if (rows > 0)
	{
		cols = solong_strlen(game->map[0]);
	}
	game->rows = rows;
	game->cols = cols;
	if (cols < 5 || rows < 3)
	{
		return (1);
	}
	return (0);
}

static int	lines(char *str)
{
	int	fd;
	int	i;
	char	*line;
	
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line && i++ >= 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (i);
}

char	**create_map(char *str)
{
	int	fd;
	char	**map;
	int	i;
	int	j;
	
	i = lines(str);
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	j = -1;
	while (++j != i)
	{
		map[j] = get_next_line(fd);
		if (!map[j])
		{
			free_map(map);
			return (NULL);
		}
	}
	map[j] = NULL;
	close(fd);
	return (map);
}

void	fill(char **map_copy, t_game *game, int x, int y)
{
	if (map_copy[y][x] == '\0' || map_copy[y][x] == '\n')
	{
		return ;
	}
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows)
	{
		return ;
	}
	if (map_copy[y][x] == 'F' || map_copy[y][x] == '1')
	{
		return ;
	}
	if(map_copy[y][x] == 'C')
	{
		map_copy[y][x] = 'F';
		game->gathered++;
	}
	else
		map_copy[y][x] = 'F';
	fill(map_copy, game, x - 1, y);
	fill(map_copy, game, x + 1, y);
	fill(map_copy, game, x, y - 1);
	fill(map_copy, game, x, y + 1);
}
