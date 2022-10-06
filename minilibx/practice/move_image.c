#include <mlx.h>
#include <stdlib.h>

# define KEY_ESCAPE_LINUX 65307
# define KEY_ESCAPE_MAC 27
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct	s_image {
	void		*img;
	int		img_width;
	int		img_height;
}	t_image;

typedef struct	s_player {
	struct s_image	image1;
	struct s_image	image2;
}	t_player;

typedef struct	s_vars {
	void	*mlx;
	void	*window;
	struct s_player	player;
	int	x_player_position;
	int	y_player_position;
}	t_vars;

/*
  int	mlx_destroy_window(void *mlx_ptr, void *img_ptr);
*/
int	draw_image(t_vars *vars)
{
	static int	flame_count;

	if (flame_count == 5000)
	{
		mlx_put_image_to_window(vars->mlx, vars->window
				, vars->player.image1.img, vars->x_player_position, vars->y_player_position);
		flame_count += 1;
	}
	else if (flame_count == 10000)
	{
		mlx_put_image_to_window(vars->mlx, vars->window
				, vars->player.image2.img, vars->x_player_position, vars->y_player_position);
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
	else if (keycode == KEY_A)
	{
		vars->x_player_position -= 32;
	}
	else if (keycode == KEY_D)
	{
		vars->x_player_position += 32;
	}
	else if (keycode == KEY_W)
	{
		vars->y_player_position -= 32;
	}
	else if (keycode == KEY_S)
	{
		vars->y_player_position += 32;
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Move image");
	vars.player.image1.img = mlx_xpm_file_to_image(vars.mlx
				, "./images/player_1_image.xpm"
				, &vars.player.image1.img_width
				, &vars.player.image1.img_height);
	vars.player.image2.img = mlx_xpm_file_to_image(vars.mlx
				, "./images/player_2_image.xpm"
				, &vars.player.image2.img_width
				, &vars.player.image2.img_height);
	vars.x_player_position = 320;
	vars.y_player_position = 240;

	mlx_key_hook(vars.window, add_coordinate, &vars);
	mlx_loop_hook(vars.mlx, draw_image, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_image(vars.mlx, vars.player.image1.img);
	mlx_destroy_image(vars.mlx, vars.player.image2.img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
