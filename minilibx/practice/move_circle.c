#include <mlx.h>

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct	s_vars_data {
	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	int	centre_x;
	int	centre_y;
	unsigned int	radius;
}	t_vars_data;

void	my_mlx_pixel_put(t_vars_data *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	draw_circle_mid_point(t_vars_data *vars)
{
	static int	flame_count = 500;
	int	adjacent;
	int	opposite;
	int	p;
	int	color;

	if (flame_count == 500)
	{
		if (vars->img)
		{
			mlx_destroy_image(vars->mlx, vars->img);
		}
		vars->img = mlx_new_image(vars->mlx, 680, 450);
		vars->addr = mlx_get_data_addr(
			vars->img
			, &vars->bits_per_pixel
			, &vars->line_length
			, &vars->endian
			);
		adjacent = vars->radius;
		opposite = 0;
		p = 1 - (int)vars->radius;
		color = 0x00FF0000;
		my_mlx_pixel_put(vars, vars->centre_x, vars->centre_y, color);
		my_mlx_pixel_put(vars, vars->centre_x + vars->radius, vars->centre_y, color);
		my_mlx_pixel_put(vars, vars->centre_x - vars->radius, vars->centre_y, color);
		my_mlx_pixel_put(vars, vars->centre_x, vars->centre_y + vars->radius, color);
		my_mlx_pixel_put(vars, vars->centre_x, vars->centre_y - vars->radius, color);
		while (opposite < adjacent)
		{
			opposite += 1;
			if (p <= 0)
				p += (2 * opposite) + 1;
			else
			{
				adjacent -= 1;
				p += (2 * opposite) - (2 * adjacent) + 1;
			}
			if (adjacent < opposite)
				break ;
			my_mlx_pixel_put(vars, vars->centre_x + adjacent, vars->centre_y + opposite, color);
			my_mlx_pixel_put(vars, vars->centre_x - adjacent, vars->centre_y - opposite, color);
			my_mlx_pixel_put(vars, vars->centre_x + adjacent, vars->centre_y - opposite, color);
			my_mlx_pixel_put(vars, vars->centre_x - adjacent, vars->centre_y + opposite, color);
			if (adjacent != opposite)
			{
				my_mlx_pixel_put(vars, vars->centre_x + opposite, vars->centre_y + adjacent, color);
				my_mlx_pixel_put(vars, vars->centre_x - opposite, vars->centre_y + adjacent, color);
				my_mlx_pixel_put(vars, vars->centre_x + opposite, vars->centre_y - adjacent, color);
				my_mlx_pixel_put(vars, vars->centre_x - opposite, vars->centre_y - adjacent, color);
			}
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
		flame_count = 0;
	}
	else
	{
		flame_count += 1;
	}
	return (0);
}

#include <stdio.h>

int	add_coordinate(int keycode, t_vars_data *vars)
{
	if (keycode == KEY_A)
	{
		vars->centre_x -= 10;
	}
	else if (keycode == KEY_D)
	{
		vars->centre_x += 10;
	}
	else if (keycode == KEY_W)
	{
		vars->centre_y -= 10;
	}
	else if (keycode == KEY_S)
	{
		vars->centre_y += 10;
	}
	printf("Press keycode is [%d] (%c)\n", keycode, keycode);
	return (0);
}

#include <stdlib.h>

int	main(void)
{
	t_vars_data	vars;

	vars.centre_x = 250;
	vars.centre_y = 250;
	vars.radius = 100;
	vars.img = NULL;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 680, 450, "Move circle");
	mlx_key_hook(vars.win, add_coordinate, &vars);
	mlx_loop_hook(vars.mlx, draw_circle_mid_point, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
