/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:12:50 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"
#include "libft.h"

static void	check_extra_newline_map(t_map_info *map_info)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < map_info->ary_size)
	{
		len = ft_strlen(map_info->game_map[i]);
		if (len == 0 && i != (map_info->ary_size - 1))
		{
			map_frees(map_info->game_map, map_info->ary_size);
			exit_write_error_message(Extra_new_line);
		}
		i += 1;
	}
}

static int	count_map_height(char **map)
{
	int	height;

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

static void	check_rectangular_map(t_map_info *map_info)
{
	int	row;
	int	width;

	row = 1;
	width = 0;
	map_info->height = count_map_height(map_info->game_map);
	map_info->width = ft_strlen(map_info->game_map[0]);
	if (map_info->height == map_info->width)
	{
		map_frees(map_info->game_map, map_info->ary_size);
		exit_write_error_message(Not_rectangular_map);
	}
	while (row < map_info->height)
	{
		width = ft_strlen(map_info->game_map[row]);
		if (width != map_info->width)
		{
			map_frees(map_info->game_map, map_info->ary_size);
			exit_write_error_message(Not_rectangular_map);
		}
		width = 0;
		row += 1;
	}
}

void	parse_game_map(t_map_info *map_info)
{
	check_extra_newline_map(map_info);
	check_rectangular_map(map_info);
	check_surrounded_wall(map_info);
	check_map_elements(map_info);
	check_playable_map(map_info);
	check_crossing_wall(map_info);
}
