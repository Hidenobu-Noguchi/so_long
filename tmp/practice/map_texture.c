#include <mlx.h>
#include <stdlib.h>

# define MAP_HEIGHT 6
# define MAP_WIDTH 21
# define KEY_ESCAPE_LINUX 65307
# define KEY_ESCAPE_MAC 27

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
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
	char	field_map[MAP_HEIGHT][MAP_WIDTH] = {
		"11111111111111111111",
		"10000M00001C000M00E1",
		"10010000100001C00111",
		"1P0101001M00010000C1",
		"11111111111111111111",
		"\0",
	};
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 32 * (MAP_WIDTH - 1), 32 * (MAP_HEIGHT - 1), "map texture");

	void	*wall_img;
	int	wall_img_width;
	int	wall_img_height;
	wall_img = mlx_xpm_file_to_image(vars.mlx, "./images/wall_image.xpm", &wall_img_width, &wall_img_height);

	void	*field_img;
	int	field_img_width;
	int	field_img_height;
	field_img = mlx_xpm_file_to_image(vars.mlx, "./images/field_image.xpm", &field_img_width, &field_img_height);

	void	*collect_img;
	int	collect_img_width;
	int	collect_img_height;
	collect_img = mlx_xpm_file_to_image(vars.mlx, "./images/collectible_image.xpm", &collect_img_width, &collect_img_height);

	void	*enemy_img;
	int	enemy_img_width;
	int	enemy_img_height;
	enemy_img = mlx_xpm_file_to_image(vars.mlx, "./images/enemy_image.xpm", &enemy_img_width, &enemy_img_height);

	void	*player_img;
	int	player_img_width;
	int	player_img_height;
	player_img = mlx_xpm_file_to_image(vars.mlx, "./images/player_1_image.xpm", &player_img_width, &player_img_height);

	void	*exit_img;
	int	exit_img_width;
	int	exit_img_height;
	exit_img = mlx_xpm_file_to_image(vars.mlx, "./images/exit_image.xpm", &exit_img_width, &exit_img_height);

	int	i = 0;
	int	j = 0;
	while(field_map[i][0] != '\0')
	{
		while(field_map[i][j] != '\0')
		{
			if (field_map[i][j] == '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.window, wall_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == '0')
			{
				mlx_put_image_to_window(vars.mlx, vars.window, field_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars.mlx, vars.window, collect_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == 'M')
			{
				mlx_put_image_to_window(vars.mlx, vars.window, enemy_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == 'P')
			{
				mlx_put_image_to_window(vars.mlx, vars.window, player_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == 'E')
			{
				mlx_put_image_to_window(vars.mlx, vars.window, exit_img, 32 * j, 32 * i);
			}

			j += 1;
		}
		j = 0;
		i += 1;
	}
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_image(vars.mlx, wall_img);
	mlx_destroy_image(vars.mlx, field_img);
	mlx_destroy_image(vars.mlx, collect_img);
	mlx_destroy_image(vars.mlx, enemy_img);
	mlx_destroy_image(vars.mlx, player_img);
	mlx_destroy_image(vars.mlx, exit_img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
