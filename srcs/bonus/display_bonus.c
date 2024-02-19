/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:24:55 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 13:45:07 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display_tile(t_game *game, char *file, int y, int x)
{
	game->img.img = mlx_xpm_file_to_image(game->mlx, file, &game->img.img_width,
			&game->img.img_height);
	if (!game->img.img)
		destroy_free_mlx(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, x * 32, y
		* 32);
	mlx_destroy_image(game->mlx, game->img.img);
}

static void	choose_tile(t_game *game, int x, int y)
{
	if (game->map.lines[x][y] == '0' || game->map.lines[x][y] == '7')
		display_tile(game, "textures/floor.xpm", x, y);
	else if (game->map.lines[x][y] == '1')
		display_tile(game, "textures/wall.xpm", x, y);
	else if (game->map.lines[x][y] == 'C' || game->map.lines[x][y] == '8')
		display_tile(game, "textures/item.xpm", x, y);
	else if (game->map.lines[x][y] == 'P' || game->map.lines[x][y] == '6')
		display_tile(game, "textures/char_down.xpm", x, y);
	else if (game->map.lines[x][y] == 'E' || game->map.lines[x][y] == '9')
		display_tile(game, "textures/exit.xpm", x, y);
	else if (game->map.lines[x][y] == 'X')
		display_tile(game, "textures/trap.xpm", x, y);
}

void	display_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			choose_tile(game, y, x);
			x++;
		}
		y++;
	}
	game->player_pos_x = game->map.start_x;
	game->player_pos_y = game->map.start_y;
}
