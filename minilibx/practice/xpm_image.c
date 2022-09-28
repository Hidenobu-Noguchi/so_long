#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	main(void)
{
	t_vars	vars;
	void	*img;
	char	*img_path = "./image/nature.xpm";
	int	img_width;
	int	img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "xpm image");
	img = mlx_xpm_file_to_image(vars.mlx, img_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
