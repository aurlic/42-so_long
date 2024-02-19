/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:33:34 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/14 15:45:01 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_file_error(WRONG_ARG_NUMBER), -1);
	if (check_file_name(av[1]) != 0)
		return (-1);
	init_game(&game);
	init_map(&game.map);
	if (check_map(av[1], &game.map) != 0)
		return (free_map(game.map), -1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (-1);
	game.window = mlx_new_window(game.mlx, 32 * game.map.width, 32
			* game.map.height, "so_long");
	display_map(&game);
	mlx_hook(game.window, 2, 1L << 0, keypress_hook, &game);
	mlx_hook(game.window, SL_X11_EVENT_DESTROY_NOTIFY,
		0L, destroy_free_mlx, &game);
	mlx_string_put(game.mlx, game.window, 10, 20, 0xFF0000,
		"Move count:    0");
	mlx_loop(game.mlx);
	return (0);
}
