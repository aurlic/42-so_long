/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:18:40 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/08 10:26:11 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_enemy(t_game *game, int x, int y)
{
	char	pos;

	pos = game->map.lines[x][y];
	if (pos == 'X')
		return (1);
	return (0);
}

void	handle_death(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		game->events++;
		destroy_free_mlx(game);
	}
}

void	flag_death(t_game *game)
{
	char	*str;

	str = ft_itoa(game->events + 1);
	game->dead = 1;
	display_tile(game, "textures/wall.xpm", 0, 3);
	display_tile(game, "textures/wall.xpm", 0, 4);
	mlx_string_put(game->mlx, game->window, 100, 20, 0xFF0000, str);
	free(str);
	ft_printf("You stepped on a trap and died...\n");
	ft_printf("Press ESC to exit the game.\n");
}
