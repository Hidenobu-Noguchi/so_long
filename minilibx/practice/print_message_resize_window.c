#include <mlx.h>
#include <stdio.h>


typedef struct	s_vars
{
	void	*mlx;
	void	*win;
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
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello, world!!");
	// 25 == ResizeRequest; 1L<<18 == EnterWindowMask
	mlx_hook(vars.win, 25, 1L<<18, print_message_resize, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
