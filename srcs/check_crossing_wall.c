/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_crossing_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 09:22:34 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_crossing_wall_row(int row, t_map_info *info)
{
	int	column;

	column = 1;
	while (column < (info->width - 1))
	{
		if (info->game_map[row][column] != '1')
		{
			break ;
		}
		column += 1;
	}
	if (column == (info->width - 1))
	{
		map_frees(info->game_map, info->ary_size);
		exit_write_error_message(Crossing_wall);
	}
}

static void	check_row_line(t_map_info *info)
{
	int	row;

	row = 1;
	while (row < (info->height - 1))
	{
		if (info->game_map[row][1] == '1')
		{
			check_crossing_wall_row(row, info);
		}
		row += 1;
	}
}

static void	check_crossing_wall_column(int column, t_map_info *info)
{
	int	row;

	row = 1;
	while (row < (info->height - 1))
	{
		if (info->game_map[row][column] != '1')
		{
			break ;
		}
		row += 1;
	}
	if (row == (info->height - 1))
	{
		map_frees(info->game_map, info->ary_size);
		exit_write_error_message(Crossing_wall);
	}
}

static void	check_column_line(t_map_info *info)
{
	int	column;

	column = 1;
	while (column < (info->width - 1))
	{
		if (info->game_map[1][column] == '1')
		{
			check_crossing_wall_column(column, info);
		}
		column += 1;
	}
}

void	check_crossing_wall(t_map_info *map_info)
{
	check_row_line(map_info);
	check_column_line(map_info);
}
