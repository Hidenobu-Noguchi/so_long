/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enough_map_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:23:43 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enough_map_elements(t_map_info *map_info)
{
	if (map_info->collectible_count == 0)
	{
		map_frees(map_info->game_map, map_info->ary_size);
		exit_write_error_message(Not_enough_elements);
	}
	else if (map_info->free_space_count == 0)
	{
		map_frees(map_info->game_map, map_info->ary_size);
		exit_write_error_message(Not_enough_elements);
	}
	else if (map_info->exit_count != 1)
	{
		map_frees(map_info->game_map, map_info->ary_size);
		exit_write_error_message(Not_enough_elements);
	}
	else if (map_info->player_count != 1)
	{
		map_frees(map_info->game_map, map_info->ary_size);
		exit_write_error_message(Not_enough_elements);
	}
}
