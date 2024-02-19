/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:27:30 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 13:45:19 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_map(t_map *map)
{
	map->err = 0;
	map->height = 0;
	map->width = 0;
	map->nb_exit = 0;
	map->nb_start = 0;
	map->nb_collectibles = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->collected = 0;
	map->found_exits = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->events = 0;
	game->img.img_height = 0;
	game->img.img_width = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->dead = 0;
}
