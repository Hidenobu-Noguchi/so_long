#include <mlx.h>

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

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

void	draw_circle_mid_point(t_data *image, int centre_x, int centre_y, unsigned int radius)
{
	int		adjacent;
	int		opposite;
	int		p;
	int		color;

	unsigned char	t = 0;
	unsigned char	r = 255;
	unsigned char	g = 0;
	unsigned char	b = 0;
	int		yellow = 1;
	int		green = 0;
	int		cyan = 0;

	adjacent = radius;
	opposite = 0;
	p = 1 - (int)radius;
	color = create_trgb(t, r, g, b);
	my_mlx_pixel_put(image, centre_x, centre_y, 0xFFFFFFFF);
	my_mlx_pixel_put(image, centre_x + radius, centre_y, 0xFFFFFFFF);
	my_mlx_pixel_put(image, centre_x - radius, centre_y, 0xFFFFFFFF);
	my_mlx_pixel_put(image, centre_x, centre_y + radius, 0xFFFFFFFF);
	my_mlx_pixel_put(image, centre_x, centre_y - radius, 0xFFFFFFFF);
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
		my_mlx_pixel_put(image, centre_x + adjacent, centre_y + opposite, color);
		my_mlx_pixel_put(image, centre_x - adjacent, centre_y - opposite, color);
		my_mlx_pixel_put(image, centre_x + adjacent, centre_y - opposite, color);
		my_mlx_pixel_put(image, centre_x - adjacent, centre_y + opposite, color);
		if (adjacent != opposite)
		{
			my_mlx_pixel_put(image, centre_x + opposite, centre_y + adjacent, color);
			my_mlx_pixel_put(image, centre_x - opposite, centre_y + adjacent, color);
			my_mlx_pixel_put(image, centre_x + opposite, centre_y - adjacent, color);
			my_mlx_pixel_put(image, centre_x - opposite, centre_y - adjacent, color);
		}
		if (yellow == 1)
		{
			if (g < 255)
				g += 5;
			else
			{
				green = 1;
				yellow = 0;
			}
		}
		else if (green == 1)
		{
			if (0 < r)
				r -= 5;
			else
			{
				green = 0;
				cyan = 1;
			}
		}
		else if (cyan == 1)
		{
			if (b < 255)
				b += 5;
			else
				cyan = 0;
		}
		else
			g -= 5;
		color = create_trgb(t, r, g, b);
	}
}

#include <stdlib.h>

int	main(int argc, char **argv)
{
	void	*new_mlx;
	void	*new_mlx_window;
	t_data	image;

	if (argc != 4)
		return (0);
	new_mlx = mlx_init();
	new_mlx_window = mlx_new_window(new_mlx, 680, 450, "Move circle");
	image.img = mlx_new_image(new_mlx, 680, 450);
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
