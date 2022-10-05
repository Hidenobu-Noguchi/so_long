#include <mlx.h>
#include <unistd.h>

typedef struct	s_vars_data {
	void	*mlx;
	void	*window;

	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_vars_data;

/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;
*/

void	my_mlx_pixel_put(t_vars_data *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(unsigned char t
		, unsigned char r
		, unsigned char g
		, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b ,g, r, t});
}
int	create_color(void)
{
	static unsigned char	t;
	static unsigned char	r = 255;
	static unsigned char	g;
	static unsigned char	b;
	static	int	yellow = 1;
	static	int	green;
	static	int	cyan;
	static	int	blue;
	static	int	white;
	static	int	red;

	if (yellow)
	{
		if (g < 255)
			g += 5;
		else
		{
			yellow = 0;
			green = 1;
		}
	}
	else if (green)
	{
		if (0 < r)
			r -= 5;
		else
		{
			green = 0;
			cyan = 1;
		}
	}
	else if (cyan)
	{
		if (b < 255)
			b += 5;
		else
		{
			cyan = 0;
			blue = 1;
		}
	}
	else if (blue)
	{
		if (0 < g)
			g -= 5;
		else
		{
			blue = 0;
			white = 1;
		}
	}
	else if (white)
	{
		if (0 < b)
			b -= 5;
		else
		{
			white = 0;
			red = 1;
		}
	}
	else if (red)
	{
		if (r < 255)
			r += 5;
		else
		{
			red = 0;
			yellow = 1;
		}
	}
	return (create_trgb(t, r, g, b));
}

int	render_rainbow(t_vars_data *vars)
{
	static int	flame_count;

	flame_count += 1;
	if ((flame_count % 2000) == 0)
	{
		int		x;
		int		y;
		int		color;

		x = 0;
		y = 0;
		color = create_color();
		while (x < 640)
		{
			while (y < 480)
			{
				my_mlx_pixel_put(vars, x, y, color);
				y += 1;
			}
			y = 0;
			x += 1;
		}
		mlx_put_image_to_window(vars->mlx, vars->window, vars->img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_vars_data	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Render rainbow");
	vars.img = mlx_new_image(vars.mlx, 640, 480);
	vars.addr = mlx_get_data_addr(
			vars.img
			, &vars.bits_per_pixel
			, &vars.line_length
			, &vars.endian
			);
	mlx_loop_hook(vars.mlx, render_rainbow, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
