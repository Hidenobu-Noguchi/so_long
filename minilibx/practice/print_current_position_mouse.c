#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

// ON_MOUSEDOWN 4 int (*f)(int button, int x, int y, void *param);
// int	print_current_position(int button, int x, int y, void *param)
// ON_MOUSEMOVE 6 int (*f)(int x, int y, void *param);
int print_current_position(int x, int y, void *param)
{
	(void)param;
	printf("Current position [%d, %d]\n",x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Print current mouse position");
	// mlx_mouse_hook(vars.win, print_current_position, &vars);
	// 06 MotionNotify; (1L<<6) PointerMotionMask;
	// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask
	// 			, int(*f)(), void *param);
	mlx_hook(vars.window, 6, 1L<<6, print_current_position, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
