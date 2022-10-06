#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

# define KEY_ESCAPE_LINUX 65307
# define KEY_ESCAPE_MAC 27
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct	s_vars {
	void	*mlx;
	void	*window;
	int	count;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	char	steps[4];

	if (keycode == KEY_ESCAPE_LINUX || keycode == KEY_ESCAPE_MAC)
	{
		mlx_loop_end(vars->mlx);
		return (0);
	}
	else if (keycode  == KEY_A || keycode == KEY_W
			|| keycode == KEY_S || keycode == KEY_D)
	{
		sprintf(steps, "%d", vars->count);
		mlx_string_put(vars->mlx, vars->window, 580, 20, 0x00000000, steps);
		vars->count += 1;
		sprintf(steps, "%d", vars->count);
		mlx_string_put(vars->mlx, vars->window, 500, 20, 0x00FF0000, "COUNT STEPS: ");
		mlx_string_put(vars->mlx, vars->window, 580, 20, 0x00FF0000, steps);
	}
	return (0);
}

/*
** Put a string in the window.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	int  x			the x location;
** @param	int  y			the y location;
** @param	int  color		the font color;
** @param	char *string	the text to write;
** @return	int				has no return value (bc).
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
*/

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "String window");
	vars.count = 0;
	mlx_string_put(vars.mlx, vars.window, 500, 20, 0x00FF0000, "COUNT STEPS: ");
	mlx_string_put(vars.mlx, vars.window, 580, 20, 0x00FF0000, "0");

	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
