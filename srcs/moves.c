/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:56:32 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 09:18:46 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_move(t_game *game, int x, int y)
{
	char	pos;

	pos = game->map.lines[x][y];
	if (pos == '1')
		return (-1);
	else if (pos == 'E' || pos == VISITED_EXIT)
	{
		if (game->map.collected == 0)
		{
			ft_printf("Good job you found all items !\n");
			destroy_free_mlx(game);
		}
		else if (game->map.collected != 0)
		{
			ft_printf("You still need to collect items !\n");
			return (-1);
		}
	}
	else if (pos == 'C' || pos == VISITED_COLLECTIBLE)
	{
		game->map.collected--;
		game->map.lines[x][y] = '0';
	}
	return (0);
}

int	move_up(t_game *game)
{
	display_tile(game, "textures/char_up.xpm", game->player_pos_x,
		game->player_pos_y);
	if (check_move(game, game->player_pos_x - 1, game->player_pos_y) != 0)
		return (0);
	if (check_enemy(game, game->player_pos_x - 1, game->player_pos_y) != 0)
	{
		game->player_pos_x--;
		display_tile(game, "textures/char_dead.xpm", game->player_pos_x,
			game->player_pos_y);
		display_tile(game, "textures/tomb.xpm", game->player_pos_x + 1,
			game->player_pos_y);
		return (-1);
	}
	game->player_pos_x--;
	display_tile(game, "textures/char_up.xpm", game->player_pos_x,
		game->player_pos_y);
	display_tile(game, "textures/floor.xpm", game->player_pos_x + 1,
		game->player_pos_y);
	return (1);
}

int	move_down(t_game *game)
{
	display_tile(game, "textures/char_down.xpm", game->player_pos_x,
		game->player_pos_y);
	if (check_move(game, game->player_pos_x + 1, game->player_pos_y) != 0)
		return (0);
	if (check_enemy(game, game->player_pos_x + 1, game->player_pos_y) != 0)
	{
		game->player_pos_x++;
		display_tile(game, "textures/char_dead.xpm", game->player_pos_x,
			game->player_pos_y);
		display_tile(game, "textures/tomb.xpm", game->player_pos_x - 1,
			game->player_pos_y);
		return (-1);
	}
	game->player_pos_x++;
	display_tile(game, "textures/char_down.xpm", game->player_pos_x,
		game->player_pos_y);
	display_tile(game, "textures/floor.xpm", game->player_pos_x - 1,
		game->player_pos_y);
	return (1);
}

int	move_left(t_game *game)
{
	display_tile(game, "textures/char_left.xpm", game->player_pos_x,
		game->player_pos_y);
	if (check_move(game, game->player_pos_x, game->player_pos_y - 1) != 0)
		return (0);
	if (check_enemy(game, game->player_pos_x, game->player_pos_y - 1) != 0)
	{
		game->player_pos_y--;
		display_tile(game, "textures/char_dead.xpm", game->player_pos_x,
			game->player_pos_y);
		display_tile(game, "textures/tomb.xpm", game->player_pos_x,
			game->player_pos_y + 1);
		return (-1);
	}
	game->player_pos_y--;
	display_tile(game, "textures/char_left.xpm", game->player_pos_x,
		game->player_pos_y);
	display_tile(game, "textures/floor.xpm", game->player_pos_x,
		game->player_pos_y + 1);
	return (1);
}

int	move_right(t_game *game)
{
	display_tile(game, "textures/char_right.xpm", game->player_pos_x,
		game->player_pos_y);
	if (check_move(game, game->player_pos_x, game->player_pos_y + 1) != 0)
		return (0);
	if (check_enemy(game, game->player_pos_x, game->player_pos_y + 1) != 0)
	{
		game->player_pos_y++;
		display_tile(game, "textures/char_dead.xpm", game->player_pos_x,
			game->player_pos_y);
		display_tile(game, "textures/tomb.xpm", game->player_pos_x,
			game->player_pos_y - 1);
		return (-1);
	}
	game->player_pos_y++;
	display_tile(game, "textures/char_right.xpm", game->player_pos_x,
		game->player_pos_y);
	display_tile(game, "textures/floor.xpm", game->player_pos_x,
		game->player_pos_y - 1);
	return (1);
}
