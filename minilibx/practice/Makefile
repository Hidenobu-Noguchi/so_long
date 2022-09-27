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



close_escape:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_press_escape.c -L$(MLX_DIR) $(MLX_LIB)
close_escape_check_leaks:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_press_escape.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./a.out
close_cross:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_click_cross.c -L$(MLX_DIR) $(MLX_LIB)
close_cross_check_leaks:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_click_cross.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./a.out
resize_window:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_message_resize_window.c -L$(MLX_DIR) $(MLX_LIB)
press_key:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_keycode_press_key.c -L$(MLX_DIR) $(MLX_LIB)
click_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_mousecode_click_mouse.c -L$(MLX_DIR) $(MLX_LIB)
inout_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_message_move_mouse.c -L$(MLX_DIR) $(MLX_LIB)



key_hook:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) key_hook.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./a.out
mouse_hook:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) mouse_hook.c -L$(MLX_DIR) $(MLX_LIB)



move_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_current_position_mouse.c -L$(MLX_DIR) $(MLX_LIB)
angle_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_angle_position_mouse.c -L$(MLX_DIR) $(MLX_LIB)
