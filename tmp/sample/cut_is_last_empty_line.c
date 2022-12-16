/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_is_last_empty_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/14 10:41:00 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

size_t	count_map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
	{
		if (map[height][0] == '\0')
		{
			return (height);
		}
		height += 1;
	}
	return (height);
}

void	cut_is_last_empty_line(t_map_info *map_info)
{
	size_t	row;

	row = count_map_height(map_info->game_map);
	if (row == map_info->height)
	{
		return ;
	}
	free(map_info->game_map[map_info->height]);
	map_info->game_map[map_info->height] = NULL;
	map_info->game_map[row][0] = '\0';
}
