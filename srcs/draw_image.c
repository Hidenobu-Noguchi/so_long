/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 07:46:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_image(t_game_info *info)
{
	static int	flame_count;

	if (flame_count == 10000)
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->player.img_1.img,
			WIDTH_IMAGE * info->player.pos.column,
			HEIGHT_IMAGE * info->player.pos.row);
		flame_count += 1;
	}
	else if (flame_count == 20000)
	{
		mlx_put_image_to_window(info->mlx, info->window,
			info->player.img_2.img,
			WIDTH_IMAGE * info->player.pos.column,
			HEIGHT_IMAGE * info->player.pos.row);
		flame_count = 0;
	}
	else
	{
		flame_count += 1;
	}
	return (0);
}
