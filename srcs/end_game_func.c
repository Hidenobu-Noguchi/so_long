/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 07:55:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_window(t_game_info *info)
{
	if (info->mlx != NULL && info->window != NULL)
	{
		mlx_destroy_window(info->mlx, info->window);
	}
}

void	destroy_player_images(t_game_info *info)
{
	if (info->mlx != NULL && info->player.img_1.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->player.img_1.img);
	}
	if (info->mlx != NULL && info->player.img_2.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->player.img_2.img);
	}
}

void	destroy_map_parts(t_game_info *info)
{
	if (info->mlx != NULL && info->map_part_images.wall.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->map_part_images.wall.img);
	}
	if (info->mlx != NULL && info->map_part_images.field.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->map_part_images.field.img);
	}
	if (info->mlx != NULL && info->map_part_images.collect.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->map_part_images.collect.img);
	}
	if (info->mlx != NULL && info->map_part_images.enemy.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->map_part_images.enemy.img);
	}
	if (info->mlx != NULL && info->map_part_images.exit.img != NULL)
	{
		mlx_destroy_image(info->mlx, info->map_part_images.exit.img);
	}
}

void	destroy_display(t_game_info *info)
{
	if (info->mlx != NULL)
	{
		mlx_destroy_display(info->mlx);
	}
}
