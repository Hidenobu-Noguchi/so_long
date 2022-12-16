#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

// mlx_init();          -> new_window.c
// mlx_new_image();     -> new_image.c
// mlx_destroy_image(); -> new_image.c

/*
Gets the data address of the current image.

@param	void *img_ptr		the image instance;
@param	int  *bits_per_pixel	a pointer to where the bpp is written;
@param	int  *size_line		a pointer to where the line is written;
@param	int  *endian		a pointer to where the endian is written;
@return	char*			the memory address of the image.

char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
*/

int main(void)
{
	void	*mlx;
	t_data	image_data;

	mlx = mlx_init();
	image_data.img = mlx_new_image(mlx, 640, 480);
	image_data.addr = mlx_get_data_addr(
				image_data.img
				, &image_data.bits_per_pixel
				, &image_data.line_length
				, &image_data.endian
				);

	mlx_destroy_image(mlx, image_data.img);
	free(mlx);
	return (0);
}
