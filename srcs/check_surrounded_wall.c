/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounded_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:26:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"

static void	check_line_side(int row, t_map_info *info)
{
	int	column;

	column = 0;
	while (info->game_map[row][column])
	{
		if (info->game_map[row][column] != '1')
		{
			map_frees(info->game_map, info->ary_size);
			exit_write_error_message(Not_surrounded_wall);
		}
		column += 1;
	}
}

static void	check_middle_side(t_map_info *info)
{
	int	row;

	row = 1;
	while (row < (info->height - 1))
	{
		if (info->game_map[row][0] != '1')
		{
			map_frees(info->game_map, info->ary_size);
			exit_write_error_message(Not_surrounded_wall);
		}
		if (info->game_map[row][info->width - 1] != '1')
		{
			map_frees(info->game_map, info->ary_size);
			exit_write_error_message(Not_surrounded_wall);
		}
		row += 1;
	}
}

void	check_surrounded_wall(t_map_info *map_info)
{
	check_line_side(0, map_info);
	check_middle_side(map_info);
	check_line_side(map_info->height - 1, map_info);
}
