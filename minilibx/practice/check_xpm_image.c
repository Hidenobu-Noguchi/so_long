#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	main(int argc, char **argv)
{
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "map texture");

	if (argc != 2)
		return (0);
	void	*img;
	int	img_width;
	int	img_height;
	img = mlx_xpm_file_to_image(vars.mlx, argv[1], &img_width, &img_height);

	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
