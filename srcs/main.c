/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/07 10:33:10 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

typedef struct	s_image {
	void	*img;
	int	img_width;
	int	img_height;
}	t_image;

typedef struct	s_map_parts {
	struct s_image	wall;
	struct s_image	field;
	struct s_image	collectible;
	struct s_image	enemy;
	// struct s_image	player;
}	t_map_parts;

typedef struct	s_player {
	struct s_image	player;
	// int	move_count; ??
	// int	get_collect_count; ??
}	t_player;

typedef struct	s_map_info {
	char	**game_map;
	int	collectible_count;
	int	move_count;
}	t_map_info;

typedef struct	s_vars {
	void			*mlx;
	void			*window;
	struct s_map_info	map_info;
	struct s_map_parts	map_parts;
	struct s_player		player;
}	t_vars;

int main(int argc, char **argv)
{
	int	map_fd;

	map_fd = open_map_fd(argc, argv);
	(void)map_fd;
	// game_initialize(int map_fd, t_vars vars, t_image image);
	   // read map fd;
	   // parse map; end or continue
	   // get image (wall, field, collect, enemy, player, exit);
	   // mlx_init();
	   // mlx_new_window();
	   // mlx_key_hook();

	// game_loop(t_vars vars);
	   // mlx_loop_hook();
	   // mlx_loop();

	// game_end(t_vars vars);
	   // mlx_destroy_window();
	   // mlx_destroy_image(); * 7
	   // mlx_destroy_display();
	   // free();
	return (0);
}
