/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 06:22:04 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_mlx(t_game_info *info)
{
	info->mlx = mlx_init();
	if (info->mlx == NULL)
	{
		end_game(info);
		exit_perror(" ");
	}
}

static void	set_window(t_game_info *info)
{
	info->window = mlx_new_window(info->mlx,
			WIDTH_IMAGE * info->map_info.width,
			HEIGHT_IMAGE * info->map_info.height, "so_long");
	if (info->window == NULL)
	{
		end_game(info);
		exit_perror(" ");
	}
}

static void	set_xpm_file_to_image(t_game_info *info,
		t_image *image, char *file_name)
{
	image->img = mlx_xpm_file_to_image(info->mlx, file_name,
			&image->width, &image->height);
	if (image->img == NULL)
	{
		end_game(info);
		exit_perror(" ");
	}
}

void	set_game_info(t_game_info *info)
{
	set_mlx(info);
	set_window(info);
	set_xpm_file_to_image(info, &info->player.img_1,
		"./images/player_1_image.xpm");
	set_xpm_file_to_image(info, &info->player.img_2,
		"./images/player_2_image.xpm");
	set_xpm_file_to_image(info, &info->map_part_images.wall,
		"./images/wall_image.xpm");
	set_xpm_file_to_image(info, &info->map_part_images.field,
		"./images/field_image.xpm");
	set_xpm_file_to_image(info, &info->map_part_images.collect,
		"./images/collect_image.xpm");
	set_xpm_file_to_image(info, &info->map_part_images.enemy,
		"./images/enemy_image.xpm");
	set_xpm_file_to_image(info, &info->map_part_images.exit,
		"./images/exit_image.xpm");
	info->player.pos.row = info->map_info.player_pos.row;
	info->player.pos.column = info->map_info.player_pos.column;
}
