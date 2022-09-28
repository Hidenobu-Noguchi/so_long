#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	print_keycode(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Pressed Keycode is [%d]\n", keycode);
	return (0);
}

// int	mlx_loop_hook(void *mlx_ptr, int(*f)(), void *param);
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "loop hook");
	mlx_loop_hook(vars.mlx, print_keycode, &vars);
	mlx_loop(vars.mlx);
}
