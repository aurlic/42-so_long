/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:25:25 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 14:02:41 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	find_path(t_map *map, int x, int y)
{
	if (map->lines[x][y] == '1' || map->lines[x][y] == VISITED_TILE
		|| map->lines[x][y] == 'X' || map->lines[x][y] == VISITED_COLLECTIBLE
		|| map->lines[x][y] == VISITED_ENTRANCE)
		return ;
	if (map->lines[x][y] == 'P')
		map->lines[x][y] = VISITED_ENTRANCE;
	if (map->lines[x][y] == '0')
		map->lines[x][y] = VISITED_TILE;
	if (map->lines[x][y] == 'C')
	{
		map->collected++;
		map->lines[x][y] = VISITED_COLLECTIBLE;
	}
	if (map->lines[x][y] == 'E')
	{
		map->lines[x][y] = VISITED_EXIT;
		map->found_exits++;
		return ;
	}
	find_path(map, x + 1, y);
	find_path(map, x - 1, y);
	find_path(map, x, y + 1);
	find_path(map, x, y - 1);
}

int	check_path(t_map *map)
{
	find_path(map, map->start_x, map->start_y);
	if (map->collected != map->nb_collectibles || map->found_exits != 1)
		return (print_path_error(ERR_PATH), -1);
	return (0);
}
