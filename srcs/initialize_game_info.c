/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game_info_func.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:02:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:10:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_image(t_image *image)
{
	image->img = NULL;
	image->width = 0;
	image->height = 0;
}

static void	initialize_map_part_images(t_map_part_images *map_parts)
{
	initialize_image(&map_parts->wall);
	initialize_image(&map_parts->field);
	initialize_image(&map_parts->collect);
	initialize_image(&map_parts->enemy);
	initialize_image(&map_parts->exit);
}

static void	initialize_player(t_player *player)
{
	initialize_image(&player->img_1);
	initialize_image(&player->img_2);
	player->move_count = 0;
	player->get_collect_count = 0;
	player->pos.row = 0;
	player->pos.column = 0;
}

static void	initialize_map_info(t_map_info *map_info)
{
	map_info->game_map = NULL;
	map_info->ary_size = 0;
	map_info->height = 0;
	map_info->width = 0;
	map_info->collectible_count = 0;
	map_info->free_space_count = 0;
	map_info->exit_count = 0;
	map_info->player_count = 0;
	map_info->player_pos.row = 0;
	map_info->player_pos.column = 0;
}

void	initialize_game_info(t_game_info *info)
{
	info->mlx = NULL;
	info->window = NULL;
	initialize_map_info(&info->map_info);
	initialize_player(&info->player);
	initialize_map_part_images(&info->map_part_images);
}
