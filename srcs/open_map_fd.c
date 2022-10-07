/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:21:04 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/07 10:01:39 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	open_map_fd(int argc, char **argv)
{
	int	map_fd;
	char	*extension_dot_p;

	if (argc != 2)
	{
		exit_write_error_message(Wrong_args);
	}
	extension_dot_p = ft_strrchr(argv[1], '.');
	if (!extension_dot_p)
	{
		exit_write_error_message(Not_extension_ber);
	}
	else if (ft_strncmp(extension_dot_p, ".ber", 5))
	{
		exit_write_error_message(Not_extension_ber);
	}
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
	{
		exit_perror(argv[1]);
	}
	return (map_fd);
}

/*
// TEST CASE
// [not arg]
// " "

// aaa
// aaa.ber
// aaa.ber.ber
// aaa.bera

// .ber
// .ber.ber
// .ber.bera

// .ber/
// .ber/aaa.ber
// .ber/.ber
// .ber/.ber.ber
// .ber/.bera

// ..ber
// ..ber.aaa.ber
// ..ber.ber
// ..ber.bera
int main(int argc, char **argv)
{
	int	map_fd;

	map_fd = open_map_fd(argc, argv);
	(void)map_fd;
	printf("Success open()\n");
	return (0);
}
*/
