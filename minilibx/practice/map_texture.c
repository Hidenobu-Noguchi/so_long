#include <mlx.h>
#include <stdlib.h>

# define MAP_HEIGHT 6
# define MAP_WIDTH 21


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	main(void)
{
	char	field_map[MAP_HEIGHT][MAP_WIDTH] = {
		"11111111111111111111",
		"10000M00000C00000001",
		"10000000000000C00001",
		"100000000M00000000C1",
		"11111111111111111111",
		"\0",
	};
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 32 * (MAP_WIDTH - 1), 32 * (MAP_HEIGHT - 1), "map texture");

	void	*wall_img;
	int	wall_img_width;
	int	wall_img_height;
	wall_img = mlx_xpm_file_to_image(vars.mlx, "./images/wall_image.xpm", &wall_img_width, &wall_img_height);

	void	*collect_img;
	int	collect_img_width;
	int	collect_img_height;
	collect_img = mlx_xpm_file_to_image(vars.mlx, "./images/collectible_image.xpm", &collect_img_width, &collect_img_height);

	void	*enemy_img;
	int	enemy_img_width;
	int	enemy_img_height;
	enemy_img = mlx_xpm_file_to_image(vars.mlx, "./images/enemy_image.xpm", &enemy_img_width, &enemy_img_height);

	void	*field_img;
	int	field_img_width;
	int	field_img_height;
	field_img = mlx_xpm_file_to_image(vars.mlx, "./images/field_image.xpm", &field_img_width, &field_img_height);

	int	i = 0;
	int	j = 0;
	while(field_map[i][0] != '\0')
	{
		while(field_map[i][j] != '\0')
		{
			if (field_map[i][j] == '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, wall_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == '0')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, field_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, collect_img, 32 * j, 32 * i);
			}
			else if (field_map[i][j] == 'M')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, enemy_img, 32 * j, 32 * i);
			}

			j += 1;
		}
		j = 0;
		i += 1;
	}
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_image(vars.mlx, wall_img);
	mlx_destroy_image(vars.mlx, field_img);
	mlx_destroy_image(vars.mlx, collect_img);
	mlx_destroy_image(vars.mlx, enemy_img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
