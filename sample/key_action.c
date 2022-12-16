/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 07:25:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

void	move_player_position(t_game_info *info)
{
	char	*steps;

	steps = NULL;
	info->player.move_count += 1;
	ft_putnbr_fd(info->player.move_count, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	mlx_put_image_to_window(info->mlx, info->window,
		info->map_part_images.field.img,
		WIDTH_IMAGE * info->player.pos.column,
		HEIGHT_IMAGE * info->player.pos.row);
	mlx_put_image_to_window(info->mlx, info->window,
		info->map_part_images.wall.img,
		WIDTH_IMAGE * 3, 0);
	steps = ft_itoa(info->player.move_count);
	if (steps == NULL)
	{
		end_game(info);
		exit_perror(" ");
	}
	mlx_string_put(info->mlx, info->window, 0, 10, BLACK, "COUNT STEPS: ");
	mlx_string_put(info->mlx, info->window, WIDTH_IMAGE * 3, 10, BLACK, steps);
	free(steps);
}

void	try_end_game(t_game_info *info, int next_row, int next_column)
{
	if (info->map_info.game_map[next_row][next_column] == EXIT)
	{
		if (info->player.get_collect_count == info->map_info.collectible_count)
		{
			move_player_position(info);
			mlx_loop_end(info->mlx);
		}
		return ;
	}
	if (info->map_info.game_map[next_row][next_column] == ENEMY)
	{
		move_player_position(info);
		mlx_loop_end(info->mlx);
	}
}

t_player_position	try_move_player_position(t_game_info *info, int next_row, int next_column)
{
	t_player_position	next_pos;

	next_pos.row = next_row;
	next_pos.column = next_column;
	if (info->map_info.game_map[next_pos.row][next_pos.column] == WALL)
	{
		return (info->player.pos);
	}
	if (info->map_info.game_map[next_pos.row][next_pos.column] == EXIT ||
		info->map_info.game_map[next_pos.row][next_pos.column] == ENEMY)
	{
		try_end_game(info, next_row, next_column);
		return (info->player.pos);
	}
	move_player_position(info);
	if (info->map_info.game_map[next_pos.row][next_pos.column] == COLLECT)
	{
		info->player.get_collect_count += 1;
	}
	info->map_info.game_map[info->player.pos.row][info->player.pos.column] = FIELD;
	info->map_info.game_map[next_pos.row][next_pos.column] = PLAYER;
	return (next_pos);
}

int	key_action(int keycode, t_game_info *info)
{
	if (keycode == KEY_ESCAPE_LINUX || keycode == KEY_ESCAPE_MAC)
	{
		mlx_loop_end(info->mlx);
	}
	else if (keycode == KEY_A)
	{
		info->player.pos = try_move_player_position(info,
			info->player.pos.row, info->player.pos.column - 1);
	}
	else if (keycode == KEY_D)
	{
		info->player.pos = try_move_player_position(info,
			info->player.pos.row, info->player.pos.column + 1);
	}
	else if (keycode == KEY_W)
	{
		info->player.pos = try_move_player_position(info,
			info->player.pos.row - 1, info->player.pos.column);
	}
	else if (keycode == KEY_S)
	{
		info->player.pos = try_move_player_position(info,
			info->player.pos.row + 1, info->player.pos.column);
	}
	return (0);
}
/*
static bool	is_wall(char field_type)
{
	if (field_type == WALL)
	{
		return (true);
	}
	return (false);
}

bool	is_enemy(char field_type)
{
	if (field_type == ENEMY)
	{
		return (true);
	}
	return (false);
}

bool	is_collect(char field_type)
{
	if (field_type == COLLECT)
	{
		return (true);
	}
	return (false);
}

bool	is_possible_goal(t_game_info *info)
{
	if (info->player.get_collect_count == info->map_info.collectible_count)
	{
		return (true);
	}
	return (false);
}

bool	is_goal(char field_type)
{
	if (field_type == EXIT)
	{
		return (true);
	}
	return (false);
}
*/


