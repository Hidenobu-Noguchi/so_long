/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/07 12:25:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

void	set_image_in_map(t_game_info *game_info)
{
	// mlx_init();
	// mlx_new_window();
	// mlx_xpm_file_to_image();
	// mlx_put_image_to_window();
}

void	set_map_info(int fd, t_map_info *map_info)
{
	read_game_map(fd, map_info);
		// printf(GREEN"[OK]"END); printf(" : read_game_map();\n");
	parse_game_map(map_info);
		// printf(GREEN"[OK]"END); printf(" : parse_game_map();\n");
}

void	initialize_game_info(t_game_info *game_info)
{
	initialize_mlx_window(game_info);
	initialize_map_info(&game_info->map_info);
	initialize_player(&game_info->player);
	initialize_map_part_images(&game_info->map_part_images);
}

void	initialize_game(int map_fd, t_game_info *game_info)
{
	initialize_game_info(game_info);
	set_map_info(map_fd, &game_info->map_info);
	// set_image_in_map(game_info);		
	// initialize_mlx_window(game_info);
		// create_mlx_new_window(game_info);
	// set_mlx_key_hook(game_info);
}

int main(int argc, char **argv)
{
	int		map_fd;
	t_game_info	game_info;

	map_fd = open_map_fd(argc, argv);
	initialize_game(map_fd, &game_info);
	   // read map fd;               -> OK
	   // parse map; end or continue -> OK
	   // get image (wall, field, collect, enemy, player, exit);
	   // mlx_init();
	   // mlx_new_window();
	   // mlx_key_hook();
	for (int i = 0; game_info.map_info.game_map[i]; i++)
	{
		printf("%s\n", game_info.map_info.game_map[i]);
		// printf("[%d]     : %s\n", i, game_info.map_info.game_map[i]);
	}
	map_frees(game_info.map_info.game_map);
	// on_game(t_vars vars);
	   // mlx_loop_hook();
	   // mlx_loop();

	// end_game(t_vars vars);
	   // mlx_destroy_window();
	   // mlx_destroy_image(); * 7
	   // mlx_destroy_display();
	   // free();
	return (0);
}

