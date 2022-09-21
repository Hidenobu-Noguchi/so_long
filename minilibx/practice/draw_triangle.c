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
	// triangle
	// p(x, y) = p(0, 0); y = ax + b; 0 = 0a + b; b = 0;
	// p(x, y) = p(99, 99); 99 = 99a + b; a = 1;
	// y = x;
	for (int j = 0; j < 100; j++)
		for (int i = 0; i < 100; i++)
			if (i <= j)
				my_mlx_pixel_put(&image, i, j, 0x000000FF);
			else
				my_mlx_pixel_put(&image, i, j, 0x00FF0000);
	mlx_put_image_to_window(new_mlx, new_mlx_window, image.img, 0, 0);
	mlx_loop(new_mlx);
	return (0);
}
