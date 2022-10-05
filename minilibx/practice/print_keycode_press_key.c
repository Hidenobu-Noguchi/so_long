#include <mlx.h>
#include <stdio.h>


typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int	print_keycode(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Pressed keycode is [%d] (%c)\n", keycode, keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 650, 480, "Hello, world!!");
	// 2 == KeyPress;    1L<<0 == KeyPressMask

	// void	mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
	// mlx_hook(vars.win, 2, 1L<<0, print_keycode, &vars);

	// void mlx_key_hook(mlx_win_list_t *win_ptr, int (*f)(), void *param);
	mlx_key_hook(vars.win, print_keycode, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
