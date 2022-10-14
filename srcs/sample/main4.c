/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/13 02:46:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

void	map_frees(char **map)
{
	size_t	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i += 1;
	}
	free(map);
}

/*
char	*so_long_strjoin(char *s1, char *s2)
{
	char	*dst;

	dst = ft_strjoin(s1, s2);
	free(s1);
	return (dst);
}

void	create_game_map(int fd, t_map_info *map_info)
{
	char	*tmp_read_map;
	char	*buf_read_map;

	tmp_read_map = 0;
	buf_read_map = 0;
	while ((tmp_read_map = get_next_line(fd)))
	{
		buf_read_map = so_long_strjoin(buf_read_map, tmp_read_map);
		free(tmp_read_map);
		if (errno == ENOMEM)
		{
			exit_perror(" ");
		}
	}
	map_info->game_map = ft_split(buf_read_map, '\n');
	free(buf_read_map);
	if (errno == ENOMEM)
	{
		exit_perror(" ");
	}
	if (!map_info->game_map)
	{
		exit_write_error_message(Failed_read_map);
	}
}
*/

/*
char	**array_strjoin(size_t ary_size, char **source_ary, char *add_str)
{
	size_t	i;
	char	**dst_ary;

	i = 0;
	dst_ary = (char **)malloc(sizeof(char *) * (ary_size + 2));
	if (errno == ENOMEM)
	{
		map_frees(source_ary);
		return (NULL);
	}
	while(i < ary_size)
	{
		dst_ary[i] = ft_strdup(source_ary[i]);
		if (errno == ENOMEM)
		{
			map_frees(source_ary);
			map_frees(dst_ary);
			return (NULL);
		}
		i += 1;
	}
	dst_ary[i] = ft_strdup(add_str);
	if (errno == ENOMEM)
	{
		map_frees(source_ary);
		map_frees(dst_ary);
		return (NULL);
	}
	if (0 < ary_size)
	{
		map_frees(source_ary);
	}
	dst_ary[i + 1] = '\0';
	return (dst_ary);
}
*/

char	**array_strjoin(t_map_info *map, char *add_str)
{
	size_t	i;
	char	**dst_ary;

	i = 0;
	dst_ary = (char **)malloc(sizeof(char *) * (map->height + 2));
	if (errno == ENOMEM)
	{
		map_frees(map->game_map);
		return (NULL);
	}
	while(i < map->height)
	{
		dst_ary[i] = ft_strdup(map->game_map[i]);
		if (errno == ENOMEM)
		{
			map_frees(map->game_map);
			map_frees(dst_ary);
			return (NULL);
		}
		i += 1;
	}
	dst_ary[i] = ft_strdup(add_str);
	if (errno == ENOMEM)
	{
		map_frees(map->game_map);
		map_frees(dst_ary);
		return (NULL);
	}
	if (0 < map->height)
	{
		map_frees(map->game_map);
	}
	dst_ary[i + 1] = '\0';
	return (dst_ary);
}

void	create_game_map(int fd, t_map_info *map_info)
{
	// size_t	buf_read_count;
	char	*tmp_read_map;
	// char	**buf_read_map;

	// (void)map_info;
	// buf_read_count = 0;
	tmp_read_map = 0;
	// buf_read_map = 0;
	while ((tmp_read_map = get_next_line(fd)))
	{
		//buf_read_map = array_strjoin(buf_read_count, buf_read_map, tmp_read_map);
		map_info->game_map = array_strjoin(map_info, tmp_read_map);
		free(tmp_read_map);
		if (errno == ENOMEM)
		{
			exit_perror(" ");
		}
		map_info->height += 1;
	}
	// if (!buf_read_map)
	if (!map_info->game_map)
	{
		exit_write_error_message(Failed_read_map);
	}
	for (size_t i = 0; i < map_info->height; i++)
	{
		printf(GREEN"[OK]"END); printf(" : [%02ld] : %s", i, map_info->game_map[i]);
	}
	map_frees(map_info->game_map);
	/*
	// map_info->game_map = ft_split(buf_read_map, '\n');
	// free(buf_read_map);
	if (errno == ENOMEM)
	{
		exit_perror(" ");
	}
	*/
}

void	check_square_map(size_t idx, t_map_info *map_info)
{
	size_t	len;

	if (idx == 0)
	{
		return ;
	}
	len = ft_strlen(map_info->game_map[idx]);
	if (len != map_info->width)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Not_square_map);
	}
}

void	check_surrounded_wall(size_t idx, t_map_info *map_info)
{
	size_t	i;

	i = 0;
	// if (idx == 0 || idx == (map_info->height - 1))
	if (idx == 0)
	{
		while (map_info->game_map[idx][i])
		{
			if (map_info->game_map[idx][i] != '1')
			{
				map_frees(map_info->game_map);
				exit_write_error_message(Not_surrounded_wall);
			}
			i += 1;
		}
	}
	else
	{
		if (map_info->game_map[idx][0] != '1'
			|| map_info->game_map[idx][map_info->width - 1] != '1')
		{
			map_frees(map_info->game_map);
			exit_write_error_message(Not_surrounded_wall);
		}
	}
}

# define MAP_ELEMENTS "01CMEP"

bool	is_map_elements(char element)
{
	if (ft_strchr(MAP_ELEMENTS, element))
	{
		return (true);
	}
	return (false);
}

void	count_map_elements(size_t idx, t_map_info *map_info)
{
	size_t	i;
	size_t	wall_count;

	if (idx == 0 || idx == (map_info->height - 1))
	{
		return ;
	}
	i = 1;
	wall_count = 2;
	while (i < (map_info->width - 2))
	{
		if (!is_map_elements(map_info->game_map[idx][i]))
		{
			map_frees(map_info->game_map);
			exit_write_error_message(Not_map_element);
		}
		else if (map_info->game_map[idx][i] == '1')
		{
			wall_count += 1;
		}
		else if (map_info->game_map[idx][i] == 'C')
		{
			map_info->collectible_count += 1;
		}
		else if (map_info->game_map[idx][i] == 'E')
		{
			map_info->exit_count += 1;
		}
		else if (map_info->game_map[idx][i] == 'P')
		{
			map_info->player_count += 1;
		}
		i += 1;
	}
	if (wall_count == map_info->width)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Only_wall_elements);
	}
}

void	set_map_info(int fd, t_map_info *map_info)
{
	create_game_map(fd, map_info);

	/*
	// parse
	// check_surrounded_wall();
	// check_square_map();
	// count_map_elements();
	// check_map_elements(map_info);
	size_t	i;

	i = 0;
	map_info->width = ft_strlen(map_info->game_map[0]);
		printf("map_info->height = [%ld]\n", map_info->height);
	while (map_info->game_map[i])
	{
		check_square_map(i, map_info);
		printf(GREEN"[OK]"END); printf(" : check_square_map(%ld, );\n", i);
		// check_surrounded_wall(i, map_info);
		// printf(GREEN"[OK]"END); printf(" : check_surrounded(%ld, );\n", i);
		// count_map_elements(i, map_info);
		i += 1;
	}
	// check_map_elements(map_info);
	// check_row_count(map_info);
	size_t	map_height;
	printf("map_info->height = [%ld]\n", map_info->height);
	int i = 0;
	while (map_info->game_map[i])
	{
		i += 1;
	}
	printf("               i = [%d]\n", i);

	while(map_info->game_map[map_info->height][0] == '1')
	{
		 += 1;
	}
	if (map_info->height != (read_count - 1))
	{
		map_info->height = read_count;
		map_frees(map_info->game_map);
	}
	*/
}

void	initialize_game_info(t_game_info *game_info)
{
	initialize_mlx_window(game_info);
	initialize_map_info(&game_info->map_info);
	initialize_player(&game_info->player);
	initialize_map_part_images(&game_info->map_part_images);
}

void	game_initialize(int map_fd, t_game_info *game_info)
{
	initialize_game_info(game_info);
	set_map_info(map_fd, &game_info->map_info);
	// initialize_mlx_window(game_info);
		// create_mlx_new_window(game_info);
	// set_image_in_map(game_info);		
	// set_mlx_key_hook(game_info);
}

int main(int argc, char **argv)
{
	int		map_fd;
	t_game_info	game_info;

	map_fd = open_map_fd(argc, argv);
	game_initialize(map_fd, &game_info);
	   // read map fd;
	   // parse map; end or continue
	   // get image (wall, field, collect, enemy, player, exit);
	   // mlx_init();
	   // mlx_new_window();
	   // mlx_key_hook();
	 /*
	for (int i = 0; game_info.map_info.game_map[i]; i++)
	{
		printf("[%d] : %s\n", i, game_info.map_info.game_map[i]);
	}
	*/
	// map_frees(game_info.map_info.game_map);
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

