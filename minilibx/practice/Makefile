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
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
new_image:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) new_image.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
new_image_struct:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) new_image_struct.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out



line:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_line.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
square:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_square.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
circle:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_circle_midpoint.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
triangle:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) draw_triangle.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out



colors:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) colors.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out



close_escape:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_press_escape.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
close_cross:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) close_window_click_cross.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
resize_window:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_message_resize_window.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
press_key:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_keycode_press_key.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
click_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_mousecode_click_mouse.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
inout_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_message_move_mouse.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out



key_hook:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) key_hook.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
mouse_hook:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) mouse_hook.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out



move_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_current_position_mouse.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
angle_mouse:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) print_angle_position_mouse.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out



loop_hook:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) loop_hook.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
render_rainbow:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) render_rainbow.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
move_circle:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) move_circle.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out


check_xpm_image:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) check_xpm_image.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
xpm_image:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) xpm_image.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
move_image:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) move_image.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
map_texture:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) map_texture.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out

put_string:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) put_string_window.c -L$(MLX_DIR) $(MLX_LIB)
	valgrind --leak-check=full --leak-resolution=high --show-reachable=no ./a.out
