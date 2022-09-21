#include <mlx.h>
#include <stdio.h>

int main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello, world!");
	mlx_loop(mlx);
	(void)mlx_window;
	return (0);
}
