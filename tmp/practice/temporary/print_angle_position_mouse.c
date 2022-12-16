#include <mlx.h>
#include <stdio.h>

#define LEFT_CLICK 1

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

// (4) ON_MOUSEDOWN int (*f)(int button, int x, int y, void *param);
int	print_angle_move_mouse(int button, int x, int y, void *param)
{
	double	d_x;
	double	hypotense;
	double	cos;

	(void)param;
	if (button != LEFT_CLICK)
		return (0);
	d_x = (double)x;
	hypotense = ((x * x) + (y * y)) / ((x * x) + (y * y));
	cos = d_x / hypotense;
	printf("cos = [%f] ([%f] / [%f])\n", cos, d_x, hypotense);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Angle of mouse");
	// void	mlx_mouse_hook(mlx_win_list_t *win_ptr, int (*f)(), void *param);
	mlx_mouse_hook(vars.win, print_angle_move_mouse, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
