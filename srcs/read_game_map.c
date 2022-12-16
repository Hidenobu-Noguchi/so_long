/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 06:03:53 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize_game.h"
#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

static char	**dup_str_array(t_map_info *info)
{
	int		i;
	char	**dup_ary;

	i = 0;
	dup_ary = (char **)malloc(sizeof(char *) * (info->ary_size + 2));
	if (!dup_ary)
	{
		map_frees(info->game_map, info->ary_size);
		return (NULL);
	}
	while (i < info->ary_size)
	{
		dup_ary[i] = ft_strtrim(info->game_map[i], "\n");
		if (!dup_ary[i])
		{
			map_frees(info->game_map, info->ary_size);
			map_frees(dup_ary, info->ary_size + 2);
			return (NULL);
		}
		i += 1;
	}
	return (dup_ary);
}

static char	**join_str_array(t_map_info *info, char *add_str)
{
	char	**dst_ary;

	dst_ary = dup_str_array(info);
	if (dst_ary == NULL)
	{
		map_frees(info->game_map, info->ary_size);
		return (NULL);
	}
	dst_ary[info->ary_size] = ft_strtrim(add_str, "\n");
	if (!dst_ary[info->ary_size])
	{
		map_frees(info->game_map, info->ary_size);
		map_frees(dst_ary, info->ary_size + 2);
		return (NULL);
	}
	if (0 < info->ary_size)
	{
		map_frees(info->game_map, info->ary_size);
	}
	dst_ary[info->ary_size + 1] = '\0';
	return (dst_ary);
}

void	read_game_map(int fd, t_map_info *map_info)
{
	char	*tmp_read_map;

	tmp_read_map = get_next_line(fd);
	while (tmp_read_map != NULL)
	{
		map_info->game_map = join_str_array(map_info, tmp_read_map);
		free(tmp_read_map);
		if (!map_info->game_map)
		{
			exit_perror(" ");
		}
		map_info->ary_size += 1;
		tmp_read_map = get_next_line(fd);
	}
	if (map_info->game_map == NULL)
	{
		exit_write_error_message(Failed_read_map);
	}
}
