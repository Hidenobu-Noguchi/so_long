/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:25:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 10:48:11 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define END "\x1b[39m"
# define WIDTH_IMAGE 32
# define HEIGHT_IMAGE 32
# define WALL '1'
# define FIELD '0'
# define COLLECT 'C'
# define ENEMY 'M'
# define PLAYER 'P'
# define EXIT 'E'
# define KEY_ESCAPE_LINUX 65307
# define KEY_ESCAPE_MAC 27
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define BLACK 0x00000000

typedef enum enm {
	Wrong_args,
	Not_extension_ber,
	Failed_read_map,
	Extra_new_line,
	Not_rectangular_map,
	Not_surrounded_wall,
	Not_map_element,
	Not_enough_elements,
	Not_playable,
	Crossing_wall
}	t_error_num;

typedef struct s_player_position {
	int	row;
	int	column;
}	t_player_position;

typedef struct s_map_info {
	char				**game_map;
	int					ary_size;
	int					height;
	int					width;
	int					collectible_count;
	int					free_space_count;
	int					exit_count;
	int					player_count;
	t_player_position	player_pos;
}	t_map_info;

typedef struct s_image {
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct s_player {
	t_image				img_1;
	t_image				img_2;
	int					move_count;
	int					get_collect_count;
	t_player_position	pos;
}	t_player;

typedef struct s_map_part_images {
	t_image		wall;
	t_image		field;
	t_image		collect;
	t_image		enemy;
	t_image		exit;
}	t_map_part_images;

typedef struct s_game_info {
	void				*mlx;
	void				*window;
	t_map_info			map_info;
	t_player			player;
	t_map_part_images	map_part_images;
}	t_game_info;

void	exit_perror(char *subject);
void	exit_write_error_message(t_error_num num);
void	map_frees(char **map, int height);
int		key_action(int keycode, t_game_info *info);
int		close_window(t_game_info *info);
int		re_draw_map(t_game_info *info);
int		draw_image(t_game_info *info);
void	end_game(t_game_info *info);

#endif
