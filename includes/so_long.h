/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:25:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/07 12:25:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define END "\x1b[39m"

typedef enum enm {
	Wrong_args,
	Not_extension_ber,
	Not_map_data_empty_file,
	Failed_read_map,
	Extra_new_line,
	Not_rectangular_map,
	Not_surrounded_wall,
	Not_map_element,
	Not_enough_elements,
	Crossing_wall
}	error_num;

typedef struct	s_player_position {
	size_t	row;
	size_t	column;
}	t_player_position;

typedef struct	s_map_info {
	char			**game_map;
	size_t			height;
	size_t			width;
	size_t			collectible_count;
	size_t			free_space_count;
	size_t			exit_count;
	size_t			player_count;
	t_player_position	pos;
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

void	exit_perror(char *subject);
void	exit_write_error_message(error_num num);
int	open_map_fd(int argc, char **argv);
void	map_frees(char **map);

#endif
