/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possibility_goal_func.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:25:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"

bool	is_field_type_wall_enemy(char type)
{
	if (type == WALL || type == ENEMY)
	{
		return (true);
	}
	return (false);
}

bool	is_try_up(char field_type, t_test_map_info *info)
{
	if (!(is_field_type_wall_enemy(field_type)) && field_type != PASSED)
	{
		if (field_type == COLLECT)
		{
			info->collect -= 1;
		}
		return (true);
	}
	return (false);
}

bool	is_try_down(char field_type, int height, int next_row,
		t_test_map_info *info)
{
	if (next_row < (height - 1))
	{
		if (!(is_field_type_wall_enemy(field_type)) && field_type != PASSED)
		{
			if (field_type == COLLECT)
			{
				info->collect -= 1;
			}
			return (true);
		}
	}
	return (false);
}

bool	is_try_left(char field_type, t_test_map_info *info)
{
	if (!(is_field_type_wall_enemy(field_type)) && field_type != PASSED)
	{
		if (field_type == COLLECT)
		{
			info->collect -= 1;
		}
		return (true);
	}
	return (false);
}

bool	is_try_right(char field_type, int width, int next_column,
		t_test_map_info *info)
{
	if (next_column < (width - 1))
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
			if (field_type == COLLECT)
			{
				info->collect -= 1;
			}
			return (true);
		}
	}
	return (false);
}
