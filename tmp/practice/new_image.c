#include <mlx.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*image;
}	t_vars;

// mlx_init() -> new_window.c

/*
Create a new MLX compatible image.

@param	void *mlx_ptr	the mlx instance pointer;
@param	int  width	the width of the image to be created;
@param	int  height	the height of the image to be created;
@return	void*		the image instance reference.

void	*mlx_new_image(void *mlx_ptr,int width,int height);
*/

/*
Destroy an image instance.

@param	void *mlx_ptr	the mlx instance;
@param	void *img_ptr	the image instance;
@return	int		has no return value (bc).

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
*/
int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.image = mlx_new_image(vars.mlx, 640, 480);

	mlx_destroy_image(vars.mlx, vars.image);
	free(vars.mlx);
	return (0);
}
