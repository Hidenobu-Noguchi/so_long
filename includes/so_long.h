/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:25:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/13 11:25:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define END "\x1b[39m"

typedef enum enm {
	Wrong_args,
	Not_extension_ber,
	Not_map_data_empty_file,
	Failed_read_map,
	Extra_new_line,
	Not_rectangular_map,
	Not_surrounded_wall,
	Not_map_element,
	Not_enough_elements,
	Crossing_wall
}	error_num;

void	exit_perror(char *subject);
void	exit_write_error_message(error_num num);
int	open_map_fd(int argc, char **argv);

#endif
