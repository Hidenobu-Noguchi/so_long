#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

// 17 ON_DESTROY int (*f)(void *param);
int	close_window(t_vars *param)
{
	mlx_destroy_window(param->mlx, param->window);
	free(param->mlx);
	exit(0);
}

// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "close window click cross");
	// 17 DestroyNotify 1L<<17 StructureNotifyMask
	mlx_hook(vars.window, 17, 1L<<17, close_window, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
