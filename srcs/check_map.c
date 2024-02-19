/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:29:27 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 13:59:51 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	open_and_store_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCouldn't open file\n"), -1);
	if ((count_lines(file, map) != 0) || (store_map(file, map) != 0))
		return (-1);
	close(fd);
	return (0);
}

static int	check_map_format(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height - 1)
	{
		if ((int)ft_strlen(map->lines[i]) - 1 != map->width)
			return (print_map_error(ERR_MAP_RECTANGLE), -1);
		i++;
	}
	if ((int)ft_strlen(map->lines[i]) != map->width)
		return (print_map_error(ERR_MAP_RECTANGLE), -1);
	return (0);
}

static int	check_map_content(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = 0;
		while (map->lines[i][j])
		{
			if (map->lines[i][j] == 'E')
				map->nb_exit++;
			else if (map->lines[i][j] == 'P')
				store_start_pos(map, i, j);
			else if (map->lines[i][j] == 'C')
				map->nb_collectibles++;
			if (!ft_strchr("01CEP\n", map->lines[i][j]))
				return (print_map_error(WRONG_CHAR_TYPE), -1);
			j++;
		}
	}
	if (map->nb_exit != 1 || map->nb_start != 1 || map->nb_collectibles < 1)
		return (print_map_error(ERR_DUPLICATE_CHARS), -1);
	return (0);
}

static int	check_map_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (i == 0 || i == map->height - 1)
		{
			j = 0;
			while (j < map->width)
			{
				if (map->lines[i][j] != '1')
					return (print_map_error(ERR_MAP_WALLS), -1);
				j++;
			}
		}
		if (i != 0 && i != map->height - 1)
		{
			if (map->lines[i][0] != '1' || map->lines[i][map->width - 1] != '1')
				return (print_map_error(ERR_MAP_WALLS), -1);
		}
		i++;
	}
	return (0);
}

int	check_map(char *file, t_map *map)
{
	if (open_and_store_map(file, map) != 0)
		return (-1);
	if (check_map_format(map) != 0)
		return (-1);
	if (check_map_content(map) != 0)
		return (-1);
	if (check_map_walls(map) != 0)
		return (-1);
	if (check_path(map) != 0)
		return (-1);
	return (0);
}
