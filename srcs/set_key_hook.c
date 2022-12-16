/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 18:03:14 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"

void	set_key_hook(t_game_info *info)
{
	mlx_hook(info->window, DESTROY_NOTIFY,
		1L << 17, close_window, info);
	mlx_hook(info->window, FOCUS_IN, 1L << 21, re_draw_map, info);
	mlx_key_hook(info->window, key_action, info);
}
