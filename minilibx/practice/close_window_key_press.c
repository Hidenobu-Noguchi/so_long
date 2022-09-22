#include <mlx.h>
#include <stdio.h>


typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

# define KEY_ESCAPE_1 27
# define KEY_ESCAPE_2 65307
int	close_window(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE_1 || keycode == KEY_ESCAPE_2)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	print_button(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keycode is [%d]\n", keycode);
	return (0);
}

// void	mlx_hook(mlx_win_list_t *win_ptr, int x_event
// , int x_mask, int (*f)(), void *param);
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello, world!!");
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	mlx_hook(vars.win, 4, 1L<<2, print_button, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
