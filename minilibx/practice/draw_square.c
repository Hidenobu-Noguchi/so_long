#include <mlx.h>

typedef struct s_vars {
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

int	draw_square(t_data *image)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 100)
	{
		while (i < 100)
		{
			my_mlx_pixel_put(image, i, j, 0x00FF0000);
			i += 1;
		}
		i = 0;
		j += 1;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	image;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Draw Square");
	image.img = mlx_new_image(vars.mlx, 640, 480);
	image.addr = mlx_get_data_addr(
			image.img
			, &image.bits_per_pixel
			, &image.line_length
			, &image.endian
			);
	draw_square(&image);
	mlx_put_image_to_window(vars.mlx, vars.window, image.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
