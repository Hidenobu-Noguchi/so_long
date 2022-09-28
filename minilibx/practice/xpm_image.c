#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	main(void)
{
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "xpm image");

	void	*img00;
	char	*img_path00 = "./image/player/0_0.xpm";
	int	img_width00;
	int	img_height00;
	img00 = mlx_xpm_file_to_image(vars.mlx, img_path00, &img_width00, &img_height00);

	void	*img01;
	char	*img_path01 = "./image/player/0_1.xpm";
	int	img_width01;
	int	img_height01;
	img01 = mlx_xpm_file_to_image(vars.mlx, img_path01, &img_width01, &img_height01);

	void	*img02;
	char	*img_path02 = "./image/player/0_2.xpm";
	int	img_width02;
	int	img_height02;
	img02 = mlx_xpm_file_to_image(vars.mlx, img_path02, &img_width02, &img_height02);

	void	*img03;
	char	*img_path03 = "./image/player/0_3.xpm";
	int	img_width03;
	int	img_height03;
	img03 = mlx_xpm_file_to_image(vars.mlx, img_path03, &img_width03, &img_height03);



	void	*img10;
	char	*img_path10 = "./image/player/1_0.xpm";
	int	img_width10;
	int	img_height10;
	img10 = mlx_xpm_file_to_image(vars.mlx, img_path10, &img_width10, &img_height10);

	void	*img11;
	char	*img_path11 = "./image/player/1_1.xpm";
	int	img_width11;
	int	img_height11;
	img11 = mlx_xpm_file_to_image(vars.mlx, img_path11, &img_width11, &img_height11);

	void	*img12;
	char	*img_path12 = "./image/player/1_2.xpm";
	int	img_width12;
	int	img_height12;
	img12 = mlx_xpm_file_to_image(vars.mlx, img_path12, &img_width12, &img_height12);

	void	*img13;
	char	*img_path13 = "./image/player/1_3.xpm";
	int	img_width13;
	int	img_height13;
	img13 = mlx_xpm_file_to_image(vars.mlx, img_path13, &img_width13, &img_height13);

	mlx_put_image_to_window(vars.mlx, vars.win, img00, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img01, 30, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img02, 60, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img03, 90, 0);

	mlx_put_image_to_window(vars.mlx, vars.win, img10, 0, 30);
	mlx_put_image_to_window(vars.mlx, vars.win, img11, 30, 30);
	mlx_put_image_to_window(vars.mlx, vars.win, img12, 60, 30);
	mlx_put_image_to_window(vars.mlx, vars.win, img13, 90, 30);

	mlx_loop(vars.mlx);
	return (0);
}
