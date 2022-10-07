/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_perror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:24:24 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/07 09:29:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	exit_perror(char *subject)
{
	ft_putstr_fd("so_long: ", STDERR_FILENO);
	perror(subject);
	exit(EXIT_FAILURE);
}
