/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:44:48 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/06 15:44:36 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *file, t_map *map)
{
	int		i;
	char	*buf;
	int		fd;

	if (open(file, O_RDONLY | __O_DIRECTORY) > 2)
		return (ft_printf("Error\nTrying to pass a folder as argument.\n"));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCouldn't open file\n"), -1);
	i = 0;
	buf = "";
	while (buf)
	{
		buf = get_next_line(fd);
		free(buf);
		i++;
	}
	map->height = i - 1;
	map->lines = ft_calloc(map->height, sizeof(char *));
	if (!map->lines)
		return (ft_printf("Error\nFailed to allocate map.\n"), -1);
	close(fd);
	return (0);
}

int	store_map(char *file, t_map *map)
{
	int		i;
	char	*buf;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nCouldn't open file\n"), -1);
	i = 0;
	buf = "";
	while (buf)
	{
		buf = get_next_line(fd);
		if (buf)
			map->lines[i++] = ft_strdup(buf);
		free(buf);
	}
	map->width = ft_strlen(map->lines[0]) - 1;
	close(fd);
	return (0);
}

void	store_start_pos(t_map *map, int i, int j)
{
	map->nb_start++;
	map->start_x = i;
	map->start_y = j;
}
