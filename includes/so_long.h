/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:25:18 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/07 09:25:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

# define RED "\x1b[31m"
# define END "\x1b[39m"

typedef enum enm {
	Wrong_args,
	Not_extension_ber
}	error_num;

void	exit_perror(char *subject);
void	exit_write_error_message(error_num num);
int	open_map_fd(int argc, char **argv);

#endif
