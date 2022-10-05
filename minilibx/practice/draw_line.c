#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r
		, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	draw_line_bresenham(t_data *image, int start_x, int start_y, int finish_x, int finish_y)
{
	int	drawing_x;
	int	drawing_y;
	int	x_diff;
	int	y_diff;
	int	x_diff_double;
	int	y_diff_double;
	int	diff;
	int	color;

	drawing_x = start_x;
	drawing_y = start_y;
	x_diff = finish_x - start_x;
	y_diff = finish_y - start_x;
	x_diff_double = x_diff * 2;
	y_diff_double = y_diff * 2;
	diff = -1 * x_diff;
	color = create_trgb(100, 173, 255, 47);

	while (drawing_x <= finish_x)
	{
		if (0 < diff)
		{
			drawing_y += 1;
			diff -= x_diff_double;
		}
		diff += y_diff_double;
		my_mlx_pixel_put(image, drawing_x, drawing_y, color);
		drawing_x += 1;
	}
}

// mlx_init(); -> new_window.c
// mlx_new_window(); -> new_window.c
// mlx_new_image(); -> new_image.c
// mlx_get_data_addr(); -> new_image_struct.c

/*
Put an image to the given window.

@param	void *mlx_ptr	the mlx instance;
@param	void *win_ptr	the window instance;
@param	int  x		the x location of where the image ought to be placed;
@param	int  y		the y location of where the image ought to be placed;
@return	int		has no return value (bc).
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
*/

#include <stdlib.h>

int main(void)
{
	t_vars	vars;
	t_data	image;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Draw line");
	image.img = mlx_new_image(vars.mlx, 640, 480);
	image.addr = mlx_get_data_addr(
			image.img
			, &image.bits_per_pixel
			, &image.line_length
			, &image.endian
			);

	draw_line_bresenham(&image, 10, 20, 300, 200);
	mlx_put_image_to_window(vars.mlx, vars.window, image.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

/*
// argument x_coordinate and y_coordinate
int main(int argc, char **argv)
{
	void	*new_mlx;
	void	*new_mlx_window;
	t_data	image;

	if (argc != 5)
		return (0);
	new_mlx = mlx_init();
	new_mlx_window = mlx_new_window(new_mlx, 640, 480, "Draw line");
	image.img = mlx_new_image(new_mlx, 640, 480);
	image.addr = mlx_get_data_addr(
			image.img
			, &image.bits_per_pixel
			, &image.line_length
			, &image.endian
			);
	// bresenham algo
	draw_line_bresenham(&image
			, atoi(argv[1]), atoi(argv[2])
			, atoi(argv[3]), atoi(argv[4]));
	mlx_put_image_to_window(new_mlx, new_mlx_window, image.img, 0, 0);
	mlx_loop(new_mlx);
	return (0);
}
*/
