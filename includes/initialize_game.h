/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:18:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 18:01:56 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_GAME_H
# define INITIALIZE_GAME_H

# include "so_long.h"

# define MAP_ELEMENTS "01CMEP"
# define PASSED '3'
# define DESTROY_NOTIFY 17
# define FOCUS_IN 9

typedef struct s_player_position	t_player_position;
typedef struct s_map_info			t_map_info;
typedef struct s_image				t_image;
typedef struct s_player				t_player;
typedef struct s_map_part_images	t_map_part_images;
typedef struct s_game_info			t_game_info;

typedef struct s_test_map_info {
	int					height;
	int					width;
	int					collect;
	t_player_position	player_pos;
}	t_test_map_info;

void	initialize_game_info(t_game_info *info);
void	set_map_info(int fd, t_map_info *map_info);
void	set_key_hook(t_game_info *info);
bool	is_field_type_wall_enemy(char type);
bool	is_try_up(char field_type, t_test_map_info *info);
bool	is_try_down(char field_type, int height, int next_row,
			t_test_map_info *info);
bool	is_try_left(char field_type, t_test_map_info *info);
bool	is_try_right(char field_type, int width, int next_column,
			t_test_map_info *info);
void	check_surrounded_wall(t_map_info *map_info);
void	check_map_elements(t_map_info *map_info);
void	check_enough_map_elements(t_map_info *map_info);
void	check_playable_map(t_map_info *map_info);
void	check_crossing_wall(t_map_info *map_info);
void	read_game_map(int fd, t_map_info *map_info);
void	parse_game_map(t_map_info *map_info);
void	set_game_info(t_game_info *info);
void	put_images_to_window(t_game_info *info);

#endif
