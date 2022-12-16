#include <mlx.h>
#include <stdlib.h>

# define KEY_ESCAPE_LINUX 65307
# define KEY_ESCAPE_MAC 27

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

typedef struct	s_image {
	struct s_vars	wlx;
	void		*img;
	int		img_width;
	int		img_height;
}	t_image;

/*
void	*put_image(t_image image, char *path, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.wlx.mlx
				, path, &image.img_width, &image.img_height);
		mlx_put_image_to_window(image.wlx.mlx, image.wlx.window
				, image.img, x, y);
	return (image.img);
}
*/
/*
  int	mlx_destroy_window(void *mlx_ptr, void *img_ptr);
*/
int	draw_image(t_vars *vars)
{
	static int	flame_count;
	t_image		image;

	image.wlx = *vars;
	if (flame_count == 5000)
	{
		image.img = mlx_xpm_file_to_image(image.wlx.mlx
				, "./images/player/0_1.xpm"
				, &image.img_width, &image.img_height);
		mlx_put_image_to_window(image.wlx.mlx, image.wlx.window
				, image.img, 320, 240);
		mlx_destroy_image(image.wlx.mlx, image.img);
		// put_image(image, "./images/player/0_1.xpm", 320, 240);
		flame_count += 1;
	}
	else if (flame_count == 10000)
	{
		image.img = mlx_xpm_file_to_image(image.wlx.mlx
				, "./images/player/0_2.xpm"
				, &image.img_width, &image.img_height);
		mlx_put_image_to_window(image.wlx.mlx, image.wlx.window
				, image.img, 320, 240);
		mlx_destroy_image(image.wlx.mlx, image.img);
		// put_image(image, "./images/player/0_2.xpm", 320, 240);
		flame_count = 0;
	}
	else
	{
		flame_count += 1;
	}
	return (0);
}

int	add_coordinate(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE_LINUX || keycode == KEY_ESCAPE_MAC)
	{
		mlx_loop_end(vars->mlx);
		return (0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Move image");

	mlx_key_hook(vars.window, add_coordinate, &vars);
	mlx_loop_hook(vars.mlx, draw_image, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
