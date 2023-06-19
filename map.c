/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:39:22 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/06/19 15:18:41 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char *str)
{
	int	fd;
	char	**map;
	int	i;
	int	j;
	char	*line;
	
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	i++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
	{
		return (NULL);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	j = 0;
	while (j != i)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	return (map);
}

void	count(t_game *game)
{
	while()
}

int	check(int c, int r, char **map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	//vais ler linha a linha e atualizar map[i], i sendo coluna
	//guardar o mapa em "**map" e depois sim decidir se o programa vai "comecar" dependendo de paredes
	if (c < 5 || r < 3)
	{
		ft_printf("error\n");
		free_map(map);
		exit (1);
	}
	//ver se o mapa e retangular
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
		{
			ft_printf("1: invalid map\n");
			free_map(map);
			exit (1);
		}
		i++;
	}
	i = 0;
	j = 0;
	//ver se o mapa esta rodeado de parede = 1
	while (map[i])
	{
		while(map[i][j] != '\n' && i == 0)
		{
			if (!(map[0][j] == '1') || !(map[r - 1][j] == '1'))
			{
				ft_printf("2: invalid map\n");
				free_map(map);
				exit (1);
			}
			j++;
		}
		if (!(map[i][0] == '1') || !(map[i][c - 2] == '1'))
		{
			ft_printf("3: invalid map\n");
			free_map(map);
			exit (1);
		}
		i++;
		
	}
	//ver se o mapa tem 1 P, 1 C, 1 E
	/*while (map)
	{
		if (!ft_strchr(map[i++][j++], "P") || !ft_strchr(map[i++][j++], "C") || !ft_strchr(map[i++][j++], "E"))
		{
			ft_printf("invalid map\n");
			exit (1);
		}
	}*/
	return (0);
}
