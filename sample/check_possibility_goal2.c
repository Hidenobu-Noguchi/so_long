/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possibility_goal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:50:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/14 08:51:32 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

# define HEIGHT 6
# define WIDTH 11

# define PASSED '3'

typedef struct	s_pos {
	int	row;
	int	column;
}	t_pos;

/*
bool	is_moveable(char field_type, t_pos *pos)
{
	if (pos->row < 0 || (HEIGHT - 1) <= pos->row)
	{
		return (false);
	}
	if (pos->column < 0 || (WIDTH - 1) <= pos->column)
	{
		return (false);
	}
	if (field_type == '1' || field_type == 'M')
	{
		return (false);
	}
	return (true);
}
*/

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
	if (field_type == '1' || field_type == 'M')
	{
		return (false);
	}
	return (true);
}

bool	is_try_up(char field_type, int next_row, int next_column)
{
	if (0 <= next_row)
	{
		if (field_type != '1' && field_type != 'M')
		{
			if (field_type != PASSED)
			{
				return (true);
			}
		}
	}
	return (false);
}

bool	is_try_down(char field_type, int next_row, int next_column)
{
	if (next_row < (HEIGHT - 1))
	{
		if (field_type != '1' && field_type != 'M')
		{
			if (field_type != PASSED)
			{
				return (true);
			}
		}
	}
	return (false);
}

bool	is_try_left(char field_type, int next_row, int next_column)
{
	if (0 <= next_column)
	{
		if (field_type != '1' && field_type != 'M')
		{
			if (field_type != PASSED)
			{
				return (true);
			}
		}
	}
	return (false);
}

bool	is_try_right(char field_type, int next_row, int next_column)
{
	if (next_column < (WIDTH - 1))
	{
		if (field_type != '1' && field_type != 'M')
		{
			if (field_type != PASSED)
			{
				return (true);
			}
		}
	}
	return (false);
}

/*
int	try_move(char **map, t_pos *pos)
{
	if (is_try_up(map[pos->row - 1][pos->column], pos->row - 1, pos->column))
	{
		return (1);
	}
	else if (is_try_down(map[pos->row + 1][pos->column], pos->row + 1, pos->column))
	{
		return (2);
	}
	else if (is_try_left(map[pos->row][pos->column - 1], pos->row, pos->column - 1))
	{
		return (3);
	}
	else if (is_try_right(map[pos->row][pos->column + 1], pos->row, pos->column + 1))
	{
		return (4);
	}
	return (0);
}

void	move_position(int direction, t_pos *position)
{
	if (direction == 1)
	{
		position->row -= 1;
	}
	else if (direction == 2)
	{
		position->row += 1;
	}
	else if (direction == 3)
	{
		position->column -= 1;
	}
	else if (direction == 4)
	{
		position->column += 1;
	}
}
*/
bool	is_possibility_goal(char **map, int row, int column)
{
	if (!is_moveable(map[row][column], row, column))
		return (false);
	if (map[row][column] == 'E')
		return (true);
	map[row][column] = PASSED;
	if (is_try_up(map[row - 1][column], row - 1, column))
		if (is_possibility_goal(map, row - 1, column))
			return (true);
	if (is_try_down(map[row + 1][column], row + 1, column))
		if (is_possibility_goal(map, row + 1, column))
			return (true);
	if (is_try_left(map[row][column - 1], row, column - 1))
		if (is_possibility_goal(map, row, column - 1))
			return (true);
	if (is_try_right(map[row][column + 1], row, column + 1))
		if (is_possibility_goal(map, row, column + 1))
			return (true);
	map[row][column] = '0';
	return (false);
}

// bool	is_possibility_goal(char **map, t_pos *position)
/*
bool	is_possibility_goal(char **map, int row, int column)
{
	if (!is_moveable(map[row][column], row, column))
	{
		return (false);
	}
	if (map[row][column] == 'E')
	{
		printf("Good\n");
		return (true);
	}
	map[row][column] = PASSED;
	// if ((move_direction = try_move(map, position)))
	// {
	//	next_position = move_position(move_direction, position);
	//	if (is_possibility_goal(map, next_position))
	//	{
	//		return (true);
	//	}
	// }
	if (is_try_up(map[row - 1][column], row - 1, column))
	{	
		if (is_possibility_goal(map, row - 1, column))
		{
			return (true);
		}
	}
	if (is_try_down(map[row + 1][column], row + 1, column))
	{
		if (is_possibility_goal(map, row + 1, column))
		{
			return (true);
		}
	}
	if (is_try_left(map[row][column - 1], row, column - 1))
	{
		if (is_possibility_goal(map, row, column - 1))
		{
			return (true);
		}
	}
	if (is_try_right(map[row][column + 1], row, column + 1))
	{
		if (is_possibility_goal(map, row, column + 1))
		{
			return (true);
		}
	}
	map[row][column] = '0';
	printf("Wrong\n");
	return (false);
}
*/
int	main(void)
{
	// t_pos	player_position;
	char	**map = (char **)malloc(sizeof(char *) * HEIGHT);

	// player_position.row = 3;
	// player_position.column = 1;
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
