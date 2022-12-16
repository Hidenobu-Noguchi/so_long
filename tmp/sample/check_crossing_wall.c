/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_crossing_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/14 10:40:59 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

void	check_crossing_wall_row(size_t row, t_map_info *map_info)
{
	size_t	column;

	column = 1;
	while (column < (map_info->width - 1))
	{
		if (map_info->game_map[row][column] != '1')
		{
			break ;
		}
		column += 1;
	}
	if (column == (map_info->width - 1))
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Crossing_wall);
	}
}

void	check_row_line(t_map_info *map_info)
{
	size_t	row;

	row = 1;
	while (row < (map_info->height - 1))
	{
		if (map_info->game_map[row][1] == '1')
		{
			check_crossing_wall_row(row, map_info);
		}
		row += 1;
	}
}

void	check_crossing_wall_column(size_t column, t_map_info *map_info)
{
	size_t	row;

	row = 1;
	while (row < (map_info->height - 1))
	{
		if (map_info->game_map[row][column] != '1')
		{
			break ;
		}
		row += 1;
	}
	if (row == (map_info->height - 1))
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Crossing_wall);
	}
}

void	check_column_line(t_map_info *map_info)
{
	size_t	column;

	column = 1;
	while (column < (map_info->width - 1))
	{
		if (map_info->game_map[1][column] == '1')
		{
			check_crossing_wall_column(column, map_info);
		}
		column += 1;
	}
}

void	check_crossing_wall(t_map_info *map_info)
{
	check_row_line(map_info);
	check_column_line(map_info);
}
