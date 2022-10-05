#include <mlx.h>
#include <stdio.h>


typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}	t_vars;

// mlx_hook() .ver
/*
int	print_mousecode(int keycode, t_vars *vars)
{
	(void)vars;
	printf("click code is [%d]\n", keycode);
	return (0);
}
*/
// mlx_mouse_hook() . ver
// ON_MOUSEDOWN 4 int (*f)(int button, int x, int y, void *param);
int print_mousecode(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	printf("click code is [%d]\n", button);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Print Mousecode");
	// 4 == ButtonPress; 1L<<2 == ButtonPressMask
	// void	mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
	// mlx_hook(vars.win, 4, 1L<<2, print_mousecode, &vars);
	// void	mlx_mouse_hook(mlx_win_list_t *win_ptr, int (*f)(), void *param);
	// ON_MOUSEDOWN 4 int (*f)(int button, int x, int y, void *param);
	mlx_mouse_hook(vars.window, print_mousecode, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
