/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:22:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"
#include "libft.h"

static bool	is_map_elements(char element)
{
	if (ft_strchr(MAP_ELEMENTS, element))
	{
		return (true);
	}
	return (false);
}

static void	count_elements(t_map_info *info, int row, int column)
{
	if (info->game_map[row][column] == FIELD)
	{
		info->free_space_count += 1;
	}
	else if (info->game_map[row][column] == COLLECT)
	{
		info->collectible_count += 1;
	}
	else if (info->game_map[row][column] == EXIT)
	{
		info->exit_count += 1;
	}
	else if (info->game_map[row][column] == PLAYER)
	{
		info->player_count += 1;
		info->player_pos.row = row;
		info->player_pos.column = column;
	}
}

static void	count_a_row_map_elements(int row, t_map_info *info)
{
	int	column;

	column = 1;
	while (column < (info->width - 1))
	{
		if (!is_map_elements(info->game_map[row][column]))
		{
			map_frees(info->game_map, info->ary_size);
			exit_write_error_message(Not_map_element);
		}
		count_elements(info, row, column);
		column += 1;
	}
}

static void	count_map_elements(t_map_info *info)
{
	int	i;

	i = 1;
	while (i < (info->height - 1))
	{
		count_a_row_map_elements(i, info);
		i += 1;
	}
}

void	check_map_elements(t_map_info *map_info)
{
	count_map_elements(map_info);
	check_enough_map_elements(map_info);
}
