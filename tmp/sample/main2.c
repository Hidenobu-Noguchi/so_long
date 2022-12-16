/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/12 03:07:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

void	safe_free(char **str)
{
	if (!str[0])
	{
		free(str[0]);
	}
	str[0] = NULL;
	if (!str)
	{
		free(str);
	}
	str = NULL;
}

void	map_frees(char ***data)
{
	int	i;

	i = 0;
	while (!data[0][i])
	{
		safe_free(&data[0][i]);
		i += 1;
	}
	// safe_free(&data[0][i]);
	if (!data[0])
	{
		free(data[0]);
	}
	data[0] = NULL;
	if (!data)
	{
		free(data);
	}
	data = NULL;
}

void	create_game_map_and_parse(int fd, t_game_info *game_info)
{
	size_t	i;
	char	*read_buf;
	char	**buf_game_map;
	char	**tmp_game_map;
	
	i = 0;
	while (i < 1)
	{
		read_buf = get_next_line(fd);
		if (!read_buf)
		{
			break ;
		}
		// printf("-----------------------\n");
		// printf(GREEN"[OK]"END); printf(": read_buf\n");
		// tmp_game_map = (char **)ft_calloc(game_info->map_info.height + 2, sizeof(char *));
		tmp_game_map = (char **)malloc(sizeof(char *) * (game_info->map_info.height + 2));
		if (errno == ENOMEM)
		{
			// safe_free(&read_buf);
			free(read_buf);
			// map_frees(&tmp_game_map);
			map_frees(&buf_game_map);
			exit_perror(" ");
		}
		// printf(GREEN"[OK]"END); printf(": tmp_game_map\n");
		while (game_info->map_info.height != 0 && i < game_info->map_info.height)
		{
			// printf("	-------- while() --------\n");
			tmp_game_map[i] = ft_strdup(buf_game_map[i]);
			// printf(GREEN"	[OK]"END); printf(": tmp_game_map[%ld]\n", i);
			if (errno == ENOMEM)
			{
				safe_free(&read_buf);
				map_frees(&tmp_game_map);
				map_frees(&buf_game_map);
				exit_perror(" ");
			}
			i += 1;
		}
		tmp_game_map[i] = ft_strdup(read_buf);
		if (errno == ENOMEM)
		{
			safe_free(&read_buf);
			map_frees(&tmp_game_map);
			map_frees(&buf_game_map);
			exit_perror(" ");
		}
			// printf(GREEN"[OK]"END); printf(": ft_strdup(read_buf);\n");
		game_info->map_info.height += 1;
			// printf(GREEN"[OK]"END); printf(": increment height += 1\n");
		map_frees(&buf_game_map);
		buf_game_map = tmp_game_map;
			// printf(GREEN"[OK]"END); printf(": buf_game_map = tmp_game_map\n");
		// safe_free(&read_buf);
		free(read_buf);
			// printf(GREEN"[OK]"END); printf(": safe_free(&read_buf);\n");
		// map_frees(&tmp_game_map);
			// printf(GREEN"[OK]"END); printf(": map_frees(&tmp_game_map);\n");
		// i = 0;
		i += 1;
			// printf(GREEN"[OK]"END); printf(": increment i\n");
			// printf("-----------------------\n");
	}
	game_info->map_info.game_map = buf_game_map;
	// safe_free(&read_buf);
	// map_frees(&tmp_game_map);
	// map_frees(&buf_game_map);
	close(fd);
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
	create_game_map_and_parse(map_fd, game_info);
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
	int	i = 0;
	while(1)
	{
		if (!game_info.map_info.game_map[i])
		{
			break ;
		}
		else
		{
			printf("%s", game_info.map_info.game_map[i]);
		}
		i += 1;
	}
	map_frees(&game_info.map_info.game_map);
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

/*
char	*so_long_strjoin(char *s1, char *s2)
{
	char	*dst;

	dst = ft_strjoin(s1, s2);
	safe_free(&s1);
	return (dst);
}

	if (game_info->map_info.height == 0)
	{
		size_t	i;
			
		i = 0;
			while(read_buf[i] != '\n' && read_buf[i] != '\0')
			{
				if (read_buf[i] != '1')
				{
					map_frees(&game_info->map_info.game_map);
					free(read_buf);
					exit_write_error_message(Not_surrounded_wall);
				}
				else
				{
					i += 1;
				}
			}
			if (read_buf[i] == '\n')
			{
				game_info->map_info.height += 1;
				game_info->map_info.width = i - 1;
			}

		}
		else if (0 < game_info->map_info.height)
		{
		}
		free(read_buf);
		*/
	/*
	// read_map();
	int	read_bytes;
	char	read_buf[BUFFER_SIZE];
	char	*tmp_game_map;

	(void)game_info;
	read_bytes = -1;
	tmp_game_map = 0;
	while ((read_bytes = read(fd, read_buf, BUFFER_SIZE)) != 0)
	{
		if (read_bytes == -1)
		{
			exit_perror (" ");
		}
		tmp_game_map = so_long_strjoin(tmp_game_map, read_buf);
	}
	// create_game_map();
		// *tmp_game_map = read_buf
		// game_info->map_info.game_map = ft_split(tmp_game_map, '\n');
	int i;

	i = 0;
	game_info->map_info.game_map = ft_split(tmp_map_data, '\n');
	free(tmp_map_data);
	while (game_info->map_info.game_map[i] != 0)
	{
		printf("%s\n", game_info->map_info.game_map[i]);
		i += 1;
	}
	map_frees(&game_info->map_info.game_map);
	// parse_map();
	*/

