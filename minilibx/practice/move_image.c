#include <mlx.h>
#include <stdlib.h>

# define KEY_ESCAPE_LINUX 65307
# define KEY_ESCAPE_MAC 27
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct	s_vars_image {
	void	*mlx;
	void	*window;

	void	*img;
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
	static int	flame_count;

	if (flame_count == 500)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->img, vars->position_x, vars->position_y);
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
	if (keycode == KEY_ESCAPE_LINUX || keycode == KEY_ESCAPE_MAC)
	{
		mlx_loop_end(vars->mlx);
		return (0);
	}
	else if (keycode == KEY_A)
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
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Move image");
	vars.img = mlx_new_image(vars.mlx, 640, 480);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./images/player/0_1.xpm", &vars.img_width, &vars.img_height);
	mlx_put_image_to_window(vars.mlx, vars.window, vars.img, vars.position_x, vars.position_y);

	mlx_key_hook(vars.window, add_coordinate, &vars);
	mlx_loop_hook(vars.mlx, draw_image, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_image(vars.mlx, vars.img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
