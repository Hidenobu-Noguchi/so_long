/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possibility_goal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:50:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/13 13:03:55 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define HEIGHT 6
# define WIDTH 11

# define PASSED '3'

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


*/
static char	map[HEIGHT][WIDTH] =
{
	"1111111111",
	"1C00M011E1",
	"1110000101",
	"1P00MC0001",
	"1111111111",
};


void	move(int row, int column)
{
	int	next_row;
	int	next_column;

	next_row = 0;
	next_column = 0;
	if (column < 0 || (WIDTH - 1) <= column || row < 0 || (HEIGHT - 1) <= row
		|| map[row][column] == '1' || map[row][column] == 'M')
	{
		printf("Wrong map. Can not goal.\n");
		return ;
	}
	if (map[row][column] == 'E')
	{
		printf("Good map. Can goal.\n");
		return ;
	}
	map[row][column] = PASSED;
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
				move(next_row, next_column);
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
				move(next_row, next_column);
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
				move(next_row, next_column);
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
				move(next_row, next_column);
			}
		}
	}
	map[row][column] = '0';
}

int	main(void)
{
	//  map[5][1] = 'E';

	move(3, 1);

	return (0);
}
