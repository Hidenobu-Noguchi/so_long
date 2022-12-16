/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possibility_goal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:50:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/14 08:31:49 by hnoguchi         ###   ########.fr       */
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

bool	is_possibility_goal(char **map, t_pos *position)
{
	t_pos	next_position;

	next_position.row = 0;
	next_position.column = 0;
	// int	move_direction;

	// move_direction = 0;
	if (!is_moveable(map[position->row][position->column], position))
	{
		return (false);
	}
	if (map[position->row][position->column] == 'E')
	{
		printf("Good\n");
		return (true);
	}
	map[position->row][position->column] = PASSED;
	/*
	if ((move_direction = try_move(map, position)))
	{
		next_position = move_position(move_direction, position);
		if (is_possibility_goal(map, next_position))
		{
			return (true);
		}
	}
	*/
	if (is_try_up(map[position->row - 1][position->column], position->row - 1, position->column))
	{	
		next_position.row = position->row - 1;
		next_position.column = position->column;
		if (is_possibility_goal(map, &next_position))
		{
			return (true);
		}
	}
	if (is_try_down(map[position->row + 1][position->column], position->row + 1, position->column))
	{
		next_position.row = position->row + 1;
		next_position.column = position->column;
		if (is_possibility_goal(map, &next_position))
		{
			return (true);
		}
	}
	if (is_try_left(map[position->row][position->column - 1], position->row, position->column - 1))
	{
		next_position.row = position->row;
		next_position.column = position->column - 1;
		if (is_possibility_goal(map, &next_position))
		{
			return (true);
		}
	}
	if (is_try_right(map[position->row][position->column + 1], position->row, position->column + 1))
	{
		next_position.row = position->row;
		next_position.column = position->column + 1;
		if (is_possibility_goal(map, &next_position))
		{
			return (true);
		}
	}
	map[position->row][position->column] = '0';
	printf("Wrong\n");
	return (false);

	/*
	// try_one_up
	next_row = row - 1;
	next_column = column;
	if (0 <= next_row)
	{
		if (map[next_row][next_column] != '1'
			&& map[next_row][next_column] != 'M')
		{
			if (map[next_row][next_column] != PASSED)
			{
				if (is_possibility_goal(map, next_row, next_column))
				{
					return (true);
				}
			}
		}
	}
	// try_one_down
	next_row = row + 1;
	next_column = column;
	if (next_row < (HEIGHT - 1))
	{
		if (map[next_row][next_column] != '1'
			&& map[next_row][next_column] != 'M')
		{
			if (map[next_row][next_column] != PASSED)
			{
				if (is_possibility_goal(map, next_row, next_column))
				{
					return (true);
				}
			}
		}
	}
	// try_one_left
	next_row = row;
	next_column = column - 1;
	if (0 <= next_column)
	{
		if (map[next_row][next_column] != '1'
			&& map[next_row][next_column] != 'M')
		{
			if (map[next_row][next_column] != PASSED)
			{
				if (is_possibility_goal(map, next_row, next_column))
				{
					return (true);
				}
			}
		}
	}
	// try_one_right
	next_row = row;
	next_column = column + 1;
	if (next_column < (WIDTH - 1))
	{
		if (map[next_row][next_column] != '1'
			&& map[next_row][next_column] != 'M')
		{
			if (map[next_row][next_column] != PASSED)
			{
				if (is_possibility_goal(map, next_row, next_column))
				{
					return (true);
				}
			}
		}
	}
	map[row][column] = '0';
	return (false);
	*/
}

int	main(void)
{
	t_pos	player_position;
	char	**map = (char **)malloc(sizeof(char *) * HEIGHT);

	player_position.row = 3;
	player_position.column = 1;
	map[0] = strdup("1111111111");
	map[1] = strdup("1C00M011E1");
	map[2] = strdup("1110000111");
	map[3] = strdup("1P00MC0001");
	map[4] = strdup("1111111111");

	if(is_possibility_goal(map, &player_position))
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
/*

static char	map[HEIGHT][WIDTH] =
{
	"1111111111",
	"1C001011E1",
	"1110100101",
	"1P001C0001",
	"1111111111",
};

static char	map[HEIGHT][WIDTH] =
{
	"1111111111",
	"1C00M011E1",
	"1110M00101",
	"1P00MC0001",
	"1111111111",
};
static char	map[HEIGHT][WIDTH] =
{
	"1111111111",
	"1C001011E1",
	"1111111111",
	"1P001C0001",
	"1111111111",
};
static char	map[HEIGHT][WIDTH] =
{
	"1111111111",
	"1C001011E1",
	"1000000111",
	"1P001C0001",
	"1111111111",
};

static char	map[HEIGHT][WIDTH] =
{
	"1111111111",
	"1C00M011E1",
	"1110000101",
	"1P00MC0001",
	"1111111111",
};


*/

