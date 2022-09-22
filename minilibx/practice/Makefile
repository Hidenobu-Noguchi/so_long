CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_NAME = libmlx_linux.a
MLX_DIR = ./mlx_linux
MLX_LIB = -lmlx_Linux -lXext -lX11
MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))

.PHONY: all clean fclean bonus re new_window

all: $(MLX_NAME)

$(MLX_NAME): $(MLX_DIR)
	make -C $^

clean:
	$(RM) a.out

fclean: clean
	make clean -C $(MLX_DIR)

re: fclean all

new_window:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) new_window.c -L$(MLX_DIR) $(MLX_LIB)
new_image:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) new_image.c -L$(MLX_DIR) $(MLX_LIB)
new_image_struct:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) new_image_struct.c -L$(MLX_DIR) $(MLX_LIB)
push_image:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) push_images_window.c -L$(MLX_DIR) $(MLX_LIB)



bresenham:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_line_bresenham.c -L$(MLX_DIR) $(MLX_LIB)
square:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_square.c -L$(MLX_DIR) $(MLX_LIB)
circle:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_circle.c -L$(MLX_DIR) $(MLX_LIB)
circle_midpoint:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_circle_midpoint.c -L$(MLX_DIR) $(MLX_LIB)
triangle:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_triangle.c -L$(MLX_DIR) $(MLX_LIB)



colors:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) colors.c -L$(MLX_DIR) $(MLX_LIB)



close:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_key_press.c -L$(MLX_DIR) $(MLX_LIB)
