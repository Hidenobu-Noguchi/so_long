/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/07 09:27:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_initialize.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

static char	**array_strjoin(t_map_info *map, char *add_str)
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
