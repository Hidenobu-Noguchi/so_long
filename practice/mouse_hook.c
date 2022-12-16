#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

int	mouse_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hello from mouse_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Mouse hook");
	mlx_mouse_hook(vars.window, mouse_hook, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
