#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

int main(void)
{
	void	*mlx;
	t_data	image_data;

	mlx = mlx_init();
	image_data.img = mlx_new_image(mlx, 1920, 1080);
	image_data.addr = mlx_get_data_addr(
				image_data.img
				, &image_data.bits_per_pixel
				, &image_data.line_length
				, &image_data.endian
				);
	(void)image_data;
	return (0);
}
