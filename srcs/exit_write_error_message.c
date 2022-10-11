/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_write_error_message.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:23:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/11 08:04:05 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	exit_write_error_message(error_num num)
{
	ft_putstr_fd(RED"Usage: ", STDERR_FILENO);
	if (num == Wrong_args)
		ft_putstr_fd("Wrong arguments!"END, STDERR_FILENO);
	else if (num == Not_extension_ber)
		ft_putstr_fd("Not extension .ber"END, STDERR_FILENO);
	else if (num == Not_surrounded_wall)
		ft_putstr_fd("Not surrounded wall. This file is wrong."END, STDERR_FILENO);
	else if (num == Not_map_data_empty_file)
		ft_putstr_fd("Not map data. This file is empty."END, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
