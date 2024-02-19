/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:03:02 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 13:45:14 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(t_map map)
{
	int	i;

	i = 0;
	if (!map.height)
		return ;
	while (i < map.height)
	{
		free(map.lines[i]);
		i++;
	}
	free(map.lines);
}

int	destroy_free_mlx(t_game *game)
{
	if (game)
	{
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.lines)
		free_map(game->map);
	exit(0);
}

// int	destroy_free_mlx_mouse(t_game *game)
// {
// 	if (game)
// 	{
// 		if (game->window)
// 			mlx_destroy_window(game->mlx, game->window);
// 		mlx_destroy_display(game->mlx);
// 		free(game->mlx);
// 	}
// 	if (game->map.lines)
// 		free_map(game->map);
// 	exit(0);
// }
