/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:25:39 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/12 11:37:52 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	animate_colors(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = game->player_pos_x;
	y = game->player_pos_y;
	while (++i < 1250)
		display_tile(game, "textures/green.xpm", x, y);
	while (--i)
		display_tile(game, "textures/yellow.xpm", x, y);
	while (++i < 1250)
		display_tile(game, "textures/orange.xpm", x, y);
	while (--i)
		display_tile(game, "textures/red.xpm", x, y);
	while (++i < 1250)
		display_tile(game, "textures/purple.xpm", x, y);
	while (--i)
		display_tile(game, "textures/marine.xpm", x, y);
	while (++i < 1250)
		display_tile(game, "textures/blue.xpm", x, y);
	while (--i)
		display_tile(game, "textures/cyan.xpm", x, y);
}

static int	select_move(int keycode, t_game *game, int move_count)
{
	if (game->dead == 1)
		handle_death(keycode, game);
	else if (keycode == 'w')
		move_count = move_up(game);
	else if (keycode == 's')
		move_count = move_down(game);
	else if (keycode == 'a')
		move_count = move_left(game);
	else if (keycode == 'd')
		move_count = move_right(game);
	return (move_count);
}

int	keypress_hook(int keycode, t_game *game)
{
	int		move_count;
	char	*tmp;

	move_count = 0;
	if (keycode == XK_Escape)
		destroy_free_mlx(game);
	if (keycode == 'o')
		animate_colors(game);
	move_count = select_move(keycode, game, move_count);
	if (move_count == -1)
		flag_death(game);
	else if (move_count)
	{
		game->events++;
		tmp = ft_itoa(game->events);
		display_tile(game, "textures/wall.xpm", 0, 3);
		display_tile(game, "textures/wall.xpm", 0, 4);
		mlx_string_put(game->mlx, game->window, 100, 20, 0xFF0000, tmp);
		free(tmp);
	}
	return (0);
}
