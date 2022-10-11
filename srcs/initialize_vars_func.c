/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_vars_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:02:33 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/11 07:45:03 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"

void	initialize_image(t_image *image)
{
	image->img = 0;
	image->width = 0;
	image->height = 0;
}

void	initialize_map_part_images(t_map_part_images *map_parts)
{
	initialize_image(&map_parts->wall);
	initialize_image(&map_parts->field);
	initialize_image(&map_parts->collectible);
	initialize_image(&map_parts->enemy);
}

void	initialize_player(t_player *player)
{
	initialize_image(&player->img);
	player->move_count = 0;
	player->get_collect_count = 0;
}

void	initialize_map_info(t_map_info *info)
{
	info->game_map = 0;
	info->height = 0;
	info->width = 0;
	info->collectible_count = 0;
}

void	initialize_mlx_window(t_game_info *game_info)
{
	game_info->mlx = 0;
	game_info->window = 0;
}
