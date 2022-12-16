/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 10:27:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"
#include "libft.h"

static bool	is_moveable(char field_type, t_test_map_info *map,
		int row, int column)
{
	if (row == 0 || (map->height - 1) <= row)
	{
		return (false);
	}
	if (column == 0 || (map->width - 1) <= column)
	{
		return (false);
	}
	if (is_field_type_wall_enemy(field_type))
	{
		return (false);
	}
	return (true);
}

static bool	is_possibility_goal(char **map, t_test_map_info *info,
		int row, int column)
{
	if (!is_moveable(map[row][column], info, row, column))
		return (false);
	if (map[row][column] == EXIT && info->collect == 0)
		return (true);
	map[row][column] = PASSED;
	if (is_try_up(map[row - 1][column], info))
	{
		if (is_possibility_goal(map, info, row - 1, column))
			return (true);
	}
	if (is_try_down(map[row + 1][column], info->height, row + 1, info))
	{
		if (is_possibility_goal(map, info, row + 1, column))
			return (true);
	}
	if (is_try_left(map[row][column - 1], info))
	{
		if (is_possibility_goal(map, info, row, column - 1))
			return (true);
	}
	if (is_try_right(map[row][column + 1], info->width, column + 1, info))
		if (is_possibility_goal(map, info, row, column + 1))
			return (true);
	map[row][column] = FIELD;
	return (false);
}

static char	**map_dup(t_map_info *info)
{
	int		i;
	char	**dup_map;

	i = 0;
	dup_map = (char **)malloc(sizeof(char *) * info->height);
	if (!dup_map)
	{
		map_frees(info->game_map, info->ary_size);
		exit_perror(" ");
	}
	while (i < info->height)
	{
		dup_map[i] = ft_strdup(info->game_map[i]);
		if (!dup_map[i])
		{
			map_frees(dup_map, info->height);
			map_frees(info->game_map, info->ary_size);
			exit_perror(" ");
		}
		i += 1;
	}
	return (dup_map);
}

static void	set_test_map_info(t_test_map_info *test_info, t_map_info *map_info)
{
	test_info->height = map_info->height;
	test_info->width = map_info->width;
	test_info->collect = map_info->collectible_count;
	test_info->player_pos.row = map_info->player_pos.row;
	test_info->player_pos.column = map_info->player_pos.column;
}

void	check_playable_map(t_map_info *map_info)
{
	char				**test_map;
	t_test_map_info		test_info;

	set_test_map_info(&test_info, map_info);
	test_map = map_dup(map_info);
	if (!is_possibility_goal(test_map, &test_info,
			test_info.player_pos.row, test_info.player_pos.column))
	{
		map_frees(test_map, map_info->height);
		map_frees(map_info->game_map, map_info->ary_size);
		exit_write_error_message(Not_playable);
	}
	map_frees(test_map, map_info->height);
}
