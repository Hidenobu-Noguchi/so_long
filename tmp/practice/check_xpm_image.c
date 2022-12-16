#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

int	main(void)
{
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Put xpm image");

	void	*img;
	int	img_width;
	int	img_height;
	img = mlx_xpm_file_to_image(vars.mlx, "./images/wall_image.xpm", &img_width, &img_height);

	mlx_put_image_to_window(vars.mlx, vars.window, img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

/*
argument file path
int	main(int argc, char **argv)
{
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Put xpm image");

	if (argc != 2)
		return (0);
	void	*img;
	int	img_width;
	int	img_height;
	img = mlx_xpm_file_to_image(vars.mlx, argv[1], &img_width, &img_height);

	mlx_put_image_to_window(vars.mlx, vars.window, img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
*/
