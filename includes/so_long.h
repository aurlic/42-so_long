/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:23:55 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 13:39:11 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WRONG_ARG_NUMBER "Wrong number of arguments.\n"
# define ERR_FILE_NAME "Wrong type of file.\nvoid"
# define ERR_DUPLICATE_CHARS "Wrong amount of starts, exits or collectibles.\n"
# define ERR_MAP_RECTANGLE "Map isn't a rectangle.\n"
# define WRONG_CHAR_TYPE "Unrecognized character in map.\n"
# define ERR_MAP_WALLS "Map isn't closed with walls.\n"
# define ERR_PATH "No path found.\n"
# define VISITED_TILE '7'
# define VISITED_COLLECTIBLE '8'
# define VISITED_EXIT '9'
# define VISITED_ENTRANCE '6'
# define SL_X11_EVENT_DESTROY_NOTIFY 17

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}			t_data;

typedef struct s_map
{
	char	**lines;
	int		err;
	int		height;
	int		width;
	int		nb_exit;
	int		nb_start;
	int		nb_collectibles;
	int		start_x;
	int		start_y;
	int		collected;
	int		found_exits;
}			t_map;

typedef struct s_game
{
	t_map	map;
	t_data	img;
	void	*mlx;
	void	*window;
	int		events;
	int		player_pos_x;
	int		player_pos_y;
	int		dead;
}			t_game;

void	init_game(t_game *game);
void	init_map(t_map *map);

void	free_map(t_map map);
int		destroy_free_mlx(t_game *game);

void	print_file_error(char *error_message);
void	print_map_error(char *error_message);
void	print_path_error(char *error_message);

int		check_file_name(char *input_file);
int		check_map(char *file, t_map *map);

int		count_lines(char *file, t_map *map);
int		store_map(char *file, t_map *map);
void	store_start_pos(t_map *map, int i, int j);

int		check_path(t_map *map);

int		keypress_hook(int keycode, t_game *game);

void	display_map(t_game *game);
void	display_tile(t_game *game, char *file, int y, int x);

int		check_move(t_game *game, int x, int y);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

int		check_enemy(t_game *game, int x, int y);
void	handle_death(int keycode, t_game *game);
void	flag_death(t_game *game);

#endif