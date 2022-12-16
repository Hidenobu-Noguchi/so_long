#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

int	print_keycode(t_vars *vars)
{
	static int	flame_count;
	(void)vars;

	flame_count += 1;
	if ((flame_count % 50000) == 0)
	{
		printf("flame count is [%d]\n", flame_count);
		printf("vars->mlx    = [%p]\n", vars->mlx);
		printf("vars->window = [%p]\n", vars->window);
	}
	return (0);
}

// int	mlx_loop_hook(void *mlx_ptr, int(*f)(), void *param);
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "loop hook");
	mlx_loop_hook(vars.mlx, print_keycode, &vars);
	mlx_loop(vars.mlx);
}
