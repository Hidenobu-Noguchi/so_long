#include <mlx.h>
#include <stdio.h>


typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}	t_vars;

int	print_message_case_enter(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Hello!! | Enter window code is [%d]\n", keycode);
	return (0);
}

int	print_message_case_leave(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Bye!!   | Leave window code is [%d]\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "Print move mouse");
	// void	mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
	// 7 == EnterNotify; 1L<<4 == EnterWindowMask
	mlx_hook(vars.window, 7, 1L<<4, print_message_case_enter, &vars);
	// 8 == LeaveNotify; 1L<<5 == LeaveWindowMask
	mlx_hook(vars.window, 8, 1L<<5, print_message_case_leave, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
