/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possibility_goal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:50:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/07 08:40:12 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

# define HEIGHT 6
# define WIDTH 11

# define PASSED '3'

bool	is_field_type_wall_enemy(char type)
{
	if (type == '1' || type == 'M')
	{
		return (true);
	}
	return (false);
}

bool	is_moveable(char field_type, int row, int column)
{
	if (row < 0 || (HEIGHT - 1) <= row)
	{
		return (false);
	}
	if (column < 0 || (WIDTH - 1) <= column)
	{
		return (false);
	}
	if (is_field_type_wall_enemy(field_type))
	{
		return (false);
	}
	return (true);
}

bool	is_try_up(char field_type, int next_row, int next_column)
{
	if (0 <= next_row)
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	}
	return (false);
}

bool	is_try_down(char field_type, int next_row, int next_column)
{
	if (next_row < (HEIGHT - 1))
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	}
	return (false);
}

bool	is_try_left(char field_type, int next_row, int next_column)
{
	if (0 <= next_column)
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	}
	return (false);
}

bool	is_try_right(char field_type, int next_row, int next_column)
{
	if (next_column < (WIDTH - 1))
	{
		if (!(is_field_type_wall_enemy(field_type))
			&& field_type != PASSED)
		{
				return (true);
		}
	}
	return (false);
}

bool	is_possibility_goal(char **map, int row, int column)
{
	if (!is_moveable(map[row][column], row, column))
		return (false);
	if (map[row][column] == 'E')
		return (true);
	map[row][column] = PASSED;
	if (is_try_up(map[row - 1][column], row - 1, column))
	{
		if (is_possibility_goal(map, row - 1, column))
			return (true);
	}
	if (is_try_down(map[row + 1][column], row + 1, column))
	{
		if (is_possibility_goal(map, row + 1, column))
			return (true);
	}
	if (is_try_left(map[row][column - 1], row, column - 1))
	{
		if (is_possibility_goal(map, row, column - 1))
			return (true);
	}
	if (is_try_right(map[row][column + 1], row, column + 1))
		if (is_possibility_goal(map, row, column + 1))
			return (true);
	map[row][column] = '0';
	return (false);
}

/*
int	main(void)
{
	char	**map = (char **)malloc(sizeof(char *) * HEIGHT);

	map[0] = strdup("1111111111");
	map[1] = strdup("1C00M011E1");
	map[2] = strdup("1110000101");
	map[3] = strdup("1P00MC0001");
	map[4] = strdup("1111111111");
	if(is_possibility_goal(map, 3, 1))
	{
		printf("Good map.\n");
	}
	else
	{
		printf("Wrong map.\n");
	}

	free(map[0]);
	free(map[1]);
	free(map[2]);
	free(map[3]);
	free(map[4]);
	free(map);
	return (0);
}
*/
