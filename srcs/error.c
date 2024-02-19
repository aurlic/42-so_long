/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:44:49 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/06 16:25:08 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_file_error(char *error_message)
{
	ft_printf("\033[1;31m");
	ft_printf("Error\n%s", error_message);
	ft_printf("Correct usage: ./so_long {map name}.ber\n");
	ft_printf("\033[0m");
}

void	print_map_error(char *error_message)
{
	ft_printf("\033[1;31m");
	ft_printf("Error\n%s", error_message);
	ft_printf("Refer to subject for valid map format.\n");
	ft_printf("\033[0m");
}

void	print_path_error(char *error_message)
{
	ft_printf("\033[1;31m");
	ft_printf("Error\n%s", error_message);
	ft_printf("There must be a valid path in the map\n");
	ft_printf("\033[0m");
}
