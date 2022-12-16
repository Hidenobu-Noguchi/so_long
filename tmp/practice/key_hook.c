#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

# define KEY_ESCAPE_MAC 27
# define KEY_ESCAPE_LINUX 65307
int	close_window(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE_MAC || keycode == KEY_ESCAPE_LINUX)
		mlx_destroy_window(vars->mlx, vars->window);
	free(vars->mlx);
	exit (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "key_hook");
	mlx_key_hook(vars.window, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
