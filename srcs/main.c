/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 17:55:30 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"
#include "end_game.h"
#include "libft.h"
#include "get_next_line.h"

static int	open_map_fd(int argc, char **argv)
{
	int		map_fd;
	char	*extension_dot_p;

	map_fd = 0;
	if (argc != 2)
	{
		exit_write_error_message(Wrong_args);
	}
	extension_dot_p = ft_strrchr(argv[1], '.');
	if (!extension_dot_p)
	{
		exit_write_error_message(Not_extension_ber);
	}
	else if (ft_strncmp(extension_dot_p, ".ber", 5))
	{
		exit_write_error_message(Not_extension_ber);
	}
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
	{
		exit_perror(argv[1]);
	}
	return (map_fd);
}

static void	initialize_game(int map_fd, t_game_info *info)
{
	initialize_game_info(info);
	set_map_info(map_fd, &info->map_info);
	set_game_info(info);
	put_images_to_window(info);
	set_key_hook(info);
}

static void	on_game(t_game_info *info)
{
	mlx_loop_hook(info->mlx, draw_image, info);
	mlx_loop(info->mlx);
}

void	end_game(t_game_info *info)
{
	destroy_window(info);
	destroy_map_parts(info);
	destroy_player_images(info);
	destroy_display(info);
	map_frees(info->map_info.game_map, info->map_info.ary_size);
	free(info->mlx);
}

int	main(int argc, char **argv)
{
	int			map_fd;
	t_game_info	game_info;

	map_fd = open_map_fd(argc, argv);
	initialize_game(map_fd, &game_info);
	on_game(&game_info);
	end_game(&game_info);
	return (0);
}

/*
open_map_fd(); test case
// TEST CASE
// [not arg]
// " "

// aaa
// aaa.ber
// aaa.ber.ber
// aaa.bera

// .ber
// .ber.ber
// .ber.bera

// .ber/
// .ber/aaa.ber
// .ber/.ber
// .ber/.ber.ber
// .ber/.bera

// ..ber
// ..ber.aaa.ber
// ..ber.ber
// ..ber.bera
int main(int argc, char **argv)
{
	int	map_fd;

	map_fd = open_map_fd(argc, argv);
	(void)map_fd;
	printf("Success open()\n");
	return (0);
}
*/
