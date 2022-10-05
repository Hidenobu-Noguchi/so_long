#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_vars {
	void	*mlx;
	void	*window;
}	t_vars;

/*
Initialize mlx.

@return	void*	the mlx instance

void	*mlx_init();
*/

/*
Create a new window.

@param	void *mlx_ptr	the mlx instance pointer;
@param	int  size_x	the width of the window;
@param	int  size_y	the height of the window;
@param	char *title	the title of the window;
@return	void*		the window instance pointer.

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
*/

/*
Destroy a window instance.

@param	void *mlx_ptr	the mlx instance;
@param	void *win_ptr	the window instance;
@return	int		has no return value (bc).	

int mlx_destroy_window(void *mlx_ptr, void *win_ptr);
*/
int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 640, 480, "New Window");
	// Not mlx_destroy_window(); and free();
	// Not definitery or indirectory leaks;
	// mlx_loop(vars.mlx);

	mlx_destroy_window(vars.mlx, vars.window);
	free(vars.mlx);
	return (0);
}
