#include <stdio.h>
#include <stdlib.h>


int	create_trgb_unsigned_char(unsigned char t
		, unsigned char r
		, unsigned char g
		, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t_unsigned_char(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r_unsigned_char(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g_unsigned_char(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b_unsigned_char(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	create_trgb_int(int t, int r, int g, int b)
{
	if (t < 0 || 255 < t)
		return (0);
	if (r < 0 || 255 < r)
		return (0);
	if (g < 0 || 255 < g)
		return (0);
	if (b < 0 || 255 < b)
		return (0);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t_int(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r_int(int trgb)
{
	return ((trgb) >> 16 & 0xFF);
}

int	get_g_int(int trgb)
{
	return ((trgb) >> 8 & 0xFF);
}

int	get_b_int(int trgb)
{
	return (trgb & 0xFF);
}

int	main(int argc, char **argv)
{
	int	t_int;
	int	r_int;
	int	g_int;
	int	b_int;
	int	trgb;

	if (argc != 5)
		return (printf("Wrong Argument.\n"));
	t_int = atoi(argv[1]);
	r_int = atoi(argv[2]);
	g_int = atoi(argv[3]);
	b_int = atoi(argv[4]);

	trgb = create_trgb_int(t_int, r_int, g_int, b_int); 

	printf("----- create_trgb_int(); -----\n");
	printf("trgb : [%#010x]\n", trgb);
	printf("t    : [%d]\n", get_t_int(trgb));
	printf(" r   : [%d]\n", get_r_int(trgb));
	printf("  g  : [%d]\n", get_g_int(trgb));
	printf("   b : [%d]\n", get_b_int(trgb));

	printf("\n----- create_trgb_unsigned_char(); -----\n");
	printf("trgb : [%#010x]\n", create_trgb_unsigned_char(t_int, r_int, g_int, b_int));
	printf("t    : [%d]\n", get_t_unsigned_char(trgb));
	printf(" r   : [%d]\n", get_r_unsigned_char(trgb));
	printf("  g  : [%d]\n", get_g_unsigned_char(trgb));
	printf("   b : [%d]\n", get_b_unsigned_char(trgb));

	return (0);
}
