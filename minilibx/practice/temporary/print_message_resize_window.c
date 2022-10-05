#include <mlx.h>
#include <stdio.h>


typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}	t_vars;

int	print_message_resize(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Resize window code is [%d]\n", keycode);
	return (0);
}

// void	mlx_hook(mlx_win_list_t *win_ptr, int x_event
// , int x_mask, int (*f)(), void *param);
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Print message resize window");
	// 25 == ResizeRequest; 1L<<18 == EnterWindowMask
	mlx_hook(vars.window, 25, 1L<<18, print_message_resize, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
