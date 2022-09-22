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

void	draw_circle_mid_point(t_data *image, int centre_x, int centre_y, int radius)
{
	int	x;
	int	y;

	x = radius;
	y = 0;
	my_mlx_pixel_put(image, centre_x + x, centre_y + y, 0x00FF0000);
	if (0 < radius)
	{
		my_mlx_pixel_put(image, centre_x + x, centre_y - y, 0x00FF0000);
		my_mlx_pixel_put(image, centre_x + y, centre_y + x, 0x00FF0000);
		my_mlx_pixel_put(image, centre_x - y, centre_y + x, 0x00FF0000);
	}

	int	p;

	p = 1 - radius;
	while (y < x)
	{
		y += 1;
		if (p <= 0)
			p += (2 * y) + 1;
		else
		{
			x -= 1;
			p += (2 * y) - (2 * x) + 1;
		}
		if (x < y)
			break ;
		my_mlx_pixel_put(image, centre_x + x, centre_y + y, 0x00FF0000);
		my_mlx_pixel_put(image, centre_x - x, centre_y + y, 0x00FF0000);
		my_mlx_pixel_put(image, centre_x + x, centre_y - y, 0x00FF0000);
		my_mlx_pixel_put(image, centre_x - x, centre_y - y, 0x00FF0000);
		if (x != y)
		{
			my_mlx_pixel_put(image, centre_x + y, centre_y + x, 0x00FF0000);
			my_mlx_pixel_put(image, centre_x - y, centre_y + x, 0x00FF0000);
			my_mlx_pixel_put(image, centre_x + y, centre_y - x, 0x00FF0000);
			my_mlx_pixel_put(image, centre_x - y, centre_y - x, 0x00FF0000);
		}
	}
}

#include <stdlib.h>

int main(int argc, char **argv)
{
	void	*new_mlx;
	void	*new_mlx_window;
	t_data	image;

	if (argc != 4)
		return (0);
	new_mlx = mlx_init();
	new_mlx_window = mlx_new_window(new_mlx, 1920, 1080, "Hello world!");
	image.img = mlx_new_image(new_mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(
			image.img
			, &image.bits_per_pixel
			, &image.line_length
			, &image.endian
			);
	draw_circle_mid_point(&image
			, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	mlx_put_image_to_window(new_mlx, new_mlx_window, image.img, 0, 0);
	mlx_loop(new_mlx);
	return (0);
}
