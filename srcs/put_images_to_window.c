/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 08:41:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	put_wall_or_field(t_game_info *info, int width, int height)
{
	if (info->map_info.game_map[height][width] == '1')
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->map_part_images.wall.img,
			WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
	}
	else if (info->map_info.game_map[height][width] == '0')
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->map_part_images.field.img,
			WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
	}
}

static void	put_other_elements(t_game_info *info, int width, int height)
{
	if (info->map_info.game_map[height][width] == 'C')
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->map_part_images.collect.img,
			WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
	}
	else if (info->map_info.game_map[height][width] == 'M')
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->map_part_images.enemy.img,
			WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
	}
	else if (info->map_info.game_map[height][width] == 'P')
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->player.img_1.img,
			WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
	}
	else if (info->map_info.game_map[height][width] == 'E')
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->map_part_images.exit.img,
			WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
	}
}

static void	put_image(t_game_info *info, int width, int height)
{
	if (ft_strchr("10", info->map_info.game_map[height][width]))
	{
		put_wall_or_field(info, width, height);
	}
	else if (ft_strchr("CMPE", info->map_info.game_map[height][width]))
	{
		put_other_elements(info, width, height);
	}
}

void	put_images_to_window(t_game_info *info)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < info->map_info.height)
	{
		while (width < info->map_info.width)
		{
			put_image(info, width, height);
			width += 1;
		}
		width = 0;
		height += 1;
	}
	mlx_string_put(info->mlx, info->window, 0, 10, BLACK, "COUNT STEPS: ");
	mlx_string_put(info->mlx, info->window, WIDTH_IMAGE * 3, 10, BLACK, "0");
}
