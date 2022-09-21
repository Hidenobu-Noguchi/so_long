#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*mlx_image;

	mlx = mlx_init();
	mlx_image = mlx_new_image(mlx, 1920, 1080);
	(void)mlx_image;
	return (0);
}
