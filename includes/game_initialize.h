/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:18:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/13 09:01:06 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INITIALIZE_H
# define GAME_INITIALIZE_H

#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_map_info {
	char	**game_map;
	size_t	height;
	size_t	width;
	size_t	collectible_count;
	size_t	free_space_count;
	size_t	exit_count;
	size_t	player_count;
	// size_t	move_count;
}	t_map_info;

typedef struct	s_image {
	void	*img;
	size_t	height;
	size_t	width;
}	t_image;

typedef struct	s_player {
	t_image	img;
	size_t	move_count;
	size_t	get_collect_count;
}	t_player;

typedef struct	s_map_part_images {
	t_image		wall;
	t_image		field;
	t_image		collectible;
	t_image		enemy;
	t_player	player;
}	t_map_part_images;


typedef struct	s_game_info {
	void			*mlx;
	void			*window;
	t_map_info		map_info;
	t_player		player;
	t_map_part_images	map_part_images;
}	t_game_info;

void	initialize_image(t_image *image);
void	initialize_map_part_images(t_map_part_images *map_parts);
void	initialize_player(t_player *player);
void	initialize_map_info(t_map_info *info);
void	initialize_mlx_window(t_game_info *game_info);
/*
typedef struct	s_image {
	void	*img;
	int	img_width;
	int	img_height;
}	t_image;

typedef struct	s_player {
	struct s_image	img;
	int	move_count;
	int	get_collect_count;
}	t_player;

typedef struct	s_map_part_images {
	struct s_image	wall;
	struct s_image	field;
	struct s_image	collectible;
	struct s_image	enemy;
	struct s_player	player;
}	t_map_part_images;

typedef struct	s_map_info {
	char	**game_map;
	int	map_height;
	int	map_width;
	int	collectible_count;
	// int	move_count;
}	t_map_info;

typedef struct	s_vars {
	void				*mlx;
	void				*window;
	struct s_map_info		map_info;
	struct s_player			player;
	struct s_map_part_images	map_part_images;
}	t_vars;
*/

#endif
