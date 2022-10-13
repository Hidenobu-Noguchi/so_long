/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_write_error_message.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:23:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/13 11:25:21 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	exit_write_error_message(error_num num)
{
	ft_putstr_fd(RED"Error\nUsage: ", STDERR_FILENO);
	if (num == Wrong_args)
	{
		ft_putstr_fd("Wrong arguments!"END, STDERR_FILENO);
	}
	else if (num == Not_extension_ber)
	{
		ft_putstr_fd("Not extension .ber"END, STDERR_FILENO);
	}
	else if (num == Not_map_data_empty_file)
	{
		ft_putstr_fd("Not map data. This file is empty."END, STDERR_FILENO);
	}
	else if (num == Failed_read_map)
	{
		ft_putstr_fd("Failed read map. Maybe this file is empty."END, STDERR_FILENO);
	}
	else if (num == Extra_new_line)
	{
		ft_putstr_fd("Wrong map. There is extra newline in map."END, STDERR_FILENO);
	}
	else if (num == Not_rectangular_map)
	{
		ft_putstr_fd("Wrong map. Not rectangular map."END, STDERR_FILENO);
	}
	else if (num == Not_surrounded_wall)
	{
		ft_putstr_fd("Wrong map. Not surrounded wall."END, STDERR_FILENO);
	}
	else if (num == Not_map_element)
	{
		ft_putstr_fd("Wrong map. There is a not map element."END, STDERR_FILENO);
	}
	else if (num == Not_enough_elements)
	{
		ft_putstr_fd("Wrong map. Bad map elements."END, STDERR_FILENO);
	}
	else if (num == Crossing_wall)
	{
		ft_putstr_fd("Wrong map. There is a crossing wall."END, STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}
