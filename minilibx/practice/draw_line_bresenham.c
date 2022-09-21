#include <mlx.h>

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

void	draw_line_bresenham(t_data *image, int start_x, int start_y, int finish_x, int finish_y)
{
	int	drawing_x;
	int	drawing_y;
	int	x_diff;
	int	y_diff;
	int	x_diff_double;
	int	y_diff_double;
	int	diff;

	drawing_x = start_x;
	drawing_y = start_y;
	x_diff = finish_x - start_x;
	y_diff = finish_y - start_x;
	x_diff_double = 2 * x_diff;
	y_diff_double = 2 * y_diff;
	diff = -1 * x_diff;

	while (drawing_x <= finish_x)
	{
		if (0 < diff)
		{
			drawing_y += 1;
			diff -= x_diff_double;
		}
		diff += y_diff_double;
		my_mlx_pixel_put(image, drawing_x, drawing_y, 0x00FF0000);
		drawing_x += 1;
	}
}

int main(void)
{
	void	*new_mlx;
	void	*new_mlx_window;
	t_data	image;

	new_mlx = mlx_init();
	new_mlx_window = mlx_new_window(new_mlx, 1920, 1080, "Hello world!");
	image.img = mlx_new_image(new_mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(
			image.img
			, &image.bits_per_pixel
			, &image.line_length
			, &image.endian
			);
	// bresenham algo
	draw_line_bresenham(&image, 0, 0, 1920, 1080);
	mlx_put_image_to_window(new_mlx, new_mlx_window, image.img, 0, 0);
	mlx_loop(new_mlx);
	return (0);
}
