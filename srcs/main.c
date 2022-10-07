/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:02:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/07 05:07:51 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

int	open_map_fd(int argc, char **argv)
{
	if (argc != 2)
	{
		// exit() and put error message(Usage: ~)
		exit (1);
	}
	return (open(argv[1], O_RDONLY));
}

int main(int argc, char **argv)
{
	int	map_fd;

	map_fd = open_map_fd(argc, argv);
	if (map_fd == -1)
	{
		perror("so_long");
		return (0);
	}
	// game initialize
	// game loop
	// game end
	return (0);
}
