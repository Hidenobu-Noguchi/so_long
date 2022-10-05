#include <mlx.h>

# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct	s_vars_image {
	void	*mlx;
	void	*win;

	void	*img;
	/*
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	*/
	// char	*img_path;
	int	img_width;
	int	img_height;
	int	position_x;
	int	position_y;
}	t_vars_image;

/*
  int	mlx_destroy_window(void *mlx_ptr, void *img_ptr);
*/
int	draw_image(t_vars_image *vars)
{
	static int	flame_count = 500;

	if (flame_count == 500)
	{
		if (vars->img)
		{
			mlx_destroy_image(vars->mlx, vars->img);
		}
		vars->img = mlx_new_image(vars->mlx, 640, 480);
		vars->img = mlx_xpm_file_to_image(vars->mlx, "./images/player/0_1.xpm", &vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->position_x, vars->position_y);
		flame_count = 0;
	}
	else
	{
		flame_count += 1;
	}
	return (0);
}

int	add_coordinate(int keycode, t_vars_image *vars)
{
	if (keycode == KEY_A)
	{
		vars->position_x -= 20;
	}
	else if (keycode == KEY_D)
	{
		vars->position_x += 20;
	}
	else if (keycode == KEY_W)
	{
		vars->position_y -= 30;
	}
	else if (keycode == KEY_S)
	{
		vars->position_y += 30;
	}
	return (0);
}

int	main(void)
{
	t_vars_image	vars;

	vars.position_x = 320;
	vars.position_y = 240;
	vars.img = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Move image");

	mlx_key_hook(vars.win, add_coordinate, &vars);
	mlx_loop_hook(vars.mlx, draw_image, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
