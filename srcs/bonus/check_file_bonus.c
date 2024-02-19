/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurlic <aurlic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:29:30 by aurlic            #+#    #+#             */
/*   Updated: 2023/12/11 13:44:57 by aurlic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_file_name(char *input_file)
{
	int	i;

	i = 0;
	while (input_file[i] && input_file[i] != '.')
		i++;
	if (!input_file[i] || ft_strncmp(input_file + i, ".ber", 4) != 0
		|| input_file[i + 4] != '\0' || i < 1)
		return (print_file_error(ERR_FILE_NAME), -1);
	return (0);
}
