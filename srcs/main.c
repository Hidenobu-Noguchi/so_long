/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/14 11:54:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

# define WALL '1'
# define FIELD '0'
# define COLLECT 'C'
# define EMEMY 'M'
# define PLAYER 'P'
# define EXIT 'E'

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

char	**array_strjoin(t_map_info *map, char *add_str)
{
	size_t	i;
	char	**dst_ary;

	i = 0;
	dst_ary = (char **)malloc(sizeof(char *) * (map->height + 2));
	if (!dst_ary)
	{
		map_frees(map->game_map);
		return (NULL);
	}
	while(i < map->height)
	{
		dst_ary[i] = ft_strtrim(map->game_map[i], "\n");
		if (!dst_ary[i])
		{
			map_frees(map->game_map);
			map_frees(dst_ary);
			return (NULL);
		}
		i += 1;
	}
	dst_ary[i] = ft_strtrim(add_str, "\n");
	if (!dst_ary[i])
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

void	read_game_map(int fd, t_map_info *map_info)
{
	char	*tmp_read_map;

	tmp_read_map = 0;
	while ((tmp_read_map = get_next_line(fd)))
	{
		map_info->game_map = array_strjoin(map_info, tmp_read_map);
		free(tmp_read_map);
		if (!map_info->game_map)
		{
			exit_perror(" ");
		}
		map_info->height += 1;
	}
	if (!map_info->game_map)
	{
		exit_write_error_message(Failed_read_map);
	}
}

void	check_extra_newline_map(t_map_info *map_info)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < map_info->height)
	{
		len = ft_strlen(map_info->game_map[i]);
		if (len == 0 && i != (map_info->height - 1))
		{
			map_frees(map_info->game_map);
			exit_write_error_message(Extra_new_line);
		}
		i += 1;
	}
}

size_t	count_map_height(char **map)
{
	size_t	height;

	height = 0;
	while (map[height])
	{
		if (map[height][0] == '\0')
		{
			return (height);
		}
		height += 1;
	}
	return (height);
}

void	check_rectangular_map(t_map_info *map_info)
{
	size_t	row;
	size_t	width;

	row = 1;
	width = 0;
	map_info->height = count_map_height(map_info->game_map);
	map_info->width = ft_strlen(map_info->game_map[0]);
	if (map_info->height == map_info->width)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Not_rectangular_map);
	}
	while (row < map_info->height)
	{
		width = ft_strlen(map_info->game_map[row]);
		if (width != map_info->width)
		{
			map_frees(map_info->game_map);
			exit_write_error_message(Not_rectangular_map);
		}
		width = 0;
		row += 1;
	}
}

void	check_surrounded_wall(t_map_info *map_info)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (row < map_info->height)
	{
		if (row == 0 || row == (map_info->height - 1))
		{
			column = 0;
			while (map_info->game_map[row][column])
			{
				if (map_info->game_map[row][column] != '1')
				{
					map_frees(map_info->game_map);
					exit_write_error_message(Not_surrounded_wall);
				}
				column += 1;
			}
		}
		else
		{
			if (map_info->game_map[row][0] != '1'
				|| map_info->game_map[row][map_info->width - 1] != '1')
			{
				map_frees(map_info->game_map);
				exit_write_error_message(Not_surrounded_wall);
			}
		}
		row += 1;
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

void	count_a_row_map_elements(size_t row, t_map_info *map_info)
{
	size_t	column;

	column = 1;
	while (column < (map_info->width - 1))
	{
		if (!is_map_elements(map_info->game_map[row][column]))
		{
			map_frees(map_info->game_map);
			exit_write_error_message(Not_map_element);
		}
		else if (map_info->game_map[row][column] == '0')
		{
			map_info->free_space_count += 1;
		}
		else if (map_info->game_map[row][column] == 'C')
		{
			map_info->collectible_count += 1;
		}
		else if (map_info->game_map[row][column] == 'E')
		{
			map_info->exit_count += 1;
		}
		else if (map_info->game_map[row][column] == 'P')
		{
			map_info->player_count += 1;
			//map_info->pos.row = row;
			//map_info->pos.column = column;
		}
		column += 1;
	}
}

void	count_map_elements(t_map_info *map_info)
{
	size_t	i;

	i = 1;
	while (i < (map_info->height - 1))
	{
		count_a_row_map_elements(i, map_info);
		i += 1;
	}
}

void	check_enough_map_elements(t_map_info *map_info)
{
	if (map_info->collectible_count == 0)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Not_enough_elements);
	}
	else if (map_info->free_space_count == 0)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Not_enough_elements);
	}
	else if (map_info->exit_count != 1)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Not_enough_elements);
	}
	else if (map_info->player_count != 1)
	{
		map_frees(map_info->game_map);
		exit_write_error_message(Not_enough_elements);
	}
}

void	check_map_elements(t_map_info *map_info)
{
	count_map_elements(map_info);
	check_enough_map_elements(map_info);
}

/*

typedef struct	s_test_map_info {
	char			**map;
	size_t			height;
	size_t			width;
	t_test_player_position	player_position;
}	t_test_map_info;
*/

typedef struct	s_test_player_position {
	size_t	row;
	size_t	column;
}	t_test_player_position;

typedef struct	s_test_map_info {
	size_t			height;
	size_t			width;
}	t_test_map_info;

# define PASSED '3'

bool	is_field_type_wall_enemy(char type)
{
	if (type == '1' || type == 'M')
	{
		return (true);
	}
	return (false);
}

bool	is_moveable(char field_type, t_test_map_info *map, size_t row, size_t column)
{
	if (row == 0 || (map->height - 1) <= row)
	{
		return (false);
	}
	if (column == 0 || (map->width - 1) <= column)
	{
		return (false);
	}
	if (is_field_type_wall_enemy(field_type))
	{
		return (false);
	}
	return (true);
}

// bool	is_try_up(char field_type, int next_row, int next_column)
// bool	is_try_up(char field_type, size_t next_row)
bool	is_try_up(char field_type)
{
	// if (0 <= next_row)
	// {
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	// }
	return (false);
}

// bool	is_try_down(char field_type, int next_row, int next_column)
bool	is_try_down(char field_type, size_t height, size_t next_row)
{
	if (next_row < (height - 1))
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	}
	return (false);
}

// bool	is_try_left(char field_type, size_t next_column)
bool	is_try_left(char field_type)
{
	// if (0 <= next_column)
	// {
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	// }
	return (false);
}

// bool	is_try_right(char field_type, int next_row, int next_column)
bool	is_try_right(char field_type, size_t width, size_t next_column)
{
	// if (next_column < (WIDTH - 1))
	if (next_column < (width - 1))
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	}
	return (false);
}

// bool	is_possibility_goal(char **map, t_test_map_info *info int row, int column)
bool	is_possibility_goal(char **map, t_test_map_info *info, size_t row, size_t column)
{
	if (!is_moveable(map[row][column], info, row, column))
		return (false);
	if (map[row][column] == EXIT)
		return (true);
	map[row][column] = PASSED;
	if (is_try_up(map[row - 1][column]))
	{
		if (is_possibility_goal(map, info, row - 1, column))
			return (true);
	}
	if (is_try_down(map[row + 1][column], info->height, row + 1))
	{
		if (is_possibility_goal(map, info, row + 1, column))
			return (true);
	}
	if (is_try_left(map[row][column - 1]))
	{
		if (is_possibility_goal(map, info, row, column - 1))
			return (true);
	}
	if (is_try_right(map[row][column + 1], info->width, column + 1))
		if (is_possibility_goal(map, info, row, column + 1))
			return (true);
	map[row][column] = FIELD;
	return (false);
}


t_test_player_position	find_player_position(char **map)
{
	size_t			row;
	size_t			column;
	t_test_player_position	player;

	row = 0;
	column = 0;
	player.row = 0;
	player.column = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == PLAYER)
			{
				player.row = row;
				player.column = column;
				return (player);
			}
			column += 1;
		}
		row += 1;
	}
	return (player);
}

void	check_possibility_goal(t_map_info *map_info)
{
	size_t			i;
	t_test_map_info		test_info;
	t_test_player_position	player;
	char			**test_map;

	i = 0;
	test_info.height = map_info->height;
	test_info.width = map_info->width;
	player.row = 0;
	player.column = 0;
	test_map = (char **)malloc(sizeof(char *) * map_info->height);
	if (!test_map)
	{
		map_frees(map_info->game_map);
		exit_perror(" ");
	}
	while(i < map_info->height)
	{
		test_map[i] = ft_strdup(map_info->game_map[i]);
		if (!test_map[i])
		{
			map_frees(test_map);
			map_frees(map_info->game_map);
			exit_perror(" ");
		}
		i += 1;
	}
	player = find_player_position(test_map);
	if (!is_possibility_goal(test_map, &test_info, player.row, player.column))
	{
		map_frees(test_map);
		map_frees(map_info->game_map);
		exit_perror("test");
	}
	map_frees(test_map);
}

void	parse_game_map(t_map_info *map_info)
{
	check_extra_newline_map(map_info);
	check_rectangular_map(map_info);
	check_surrounded_wall(map_info);
	check_map_elements(map_info);
		printf(GREEN"[OK]"END); printf(" : check_map_elements();\n");
	check_possibility_goal(map_info);
		printf(GREEN"[OK]"END); printf(" : check_possibility_goal();\n");
	// check_crossing_wall(map_info);
	//	printf(GREEN"[OK]"END); printf(" : check_possibility_goal();\n");
}

void	set_map_info(int fd, t_map_info *map_info)
{
	read_game_map(fd, map_info);
		printf(GREEN"[OK]"END); printf(" : read_game_map();\n");
	parse_game_map(map_info);
		printf(GREEN"[OK]"END); printf(" : parse_game_map();\n");
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
	for (int i = 0; game_info.map_info.game_map[i]; i++)
	{
		printf("%s\n", game_info.map_info.game_map[i]);
		// printf("[%d]     : %s\n", i, game_info.map_info.game_map[i]);
	}
	map_frees(game_info.map_info.game_map);
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

