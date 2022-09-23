#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

// ON_MOUSEDOWN 4 int (*f)(int button, int x, int y, void *param);
int	print_current_position(int button, int x, int y, void *param)
{
	(void)button;
	(void)param;
	printf("Current position [%d, %d]\n",x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello, World!");
	mlx_mouse_hook(vars.win, print_current_position, &vars);
	mlx_loop(vars.mlx);

	return (0);
}
