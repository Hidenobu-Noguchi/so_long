NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	map_frees.c exit_write_error_message.c exit_perror.c \
	initialize_game_info.c set_map_info.c set_key_hook.c \
	is_possibility_goal_func.c \
	check_surrounded_wall.c check_map_elements.c check_enough_map_elements.c \
	check_playable_map.c check_crossing_wall.c \
	read_game_map.c parse_game_map.c \
	set_game_info.c put_images_to_window.c \
	key_action.c close_window.c re_draw_map.c draw_image.c \
	end_game_func.c

INCLUDES_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

INCLUDE = $(addprefix -I, $(INCLUDES_DIR))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

MLX_DIR = ./mlx_linux
MLX_LIB = -lmlx_Linux -lXext -lX11
MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))

LIBFT_DIR = ./libft
LIBFT_LIB = -lft
LIBFT_INCLUDE = $(addprefix -I, $(LIBFT_DIR)/includes)

.PHONY: mlx libft all clean fclean bonus re test_leaks test_overflow test_open_map_fd

all: mlx libft $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(MLX_DIR) $(MLX_LIB) -L$(LIBFT_DIR) $(LIBFT_LIB)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $(INCLUDE) $(MLX_INCLUDE) $(LIBFT_INCLUDE) $< -o $@

mlx:
	make -C $(MLX_DIR)

libft:
	make -C $(LIBFT_DIR)

bonus: all

clean:
	$(RM) -r $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	$(RM) -r $(OBJS_DIR)
	$(RM) $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

test_leaks: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX_DIR) $(MLX_LIB) -L$(LIBFT_DIR) $(LIBFT_LIB)
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/sample.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_elements/only_wall_height_two.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_elements/only_wall_width_two.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_extra_newline/first.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_extra_newline/in_map.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_extra_newline/last.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_extra_newline/only.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_multiple_E.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_multiple_P.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_not_0.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_not_C.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_not_E.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_not_P.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_map_elements/has_wrong_element.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/large_square.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/long_first.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/long_in_map.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/long_last.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/short_first.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/short_in_map.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/short_last.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_rectangular/small_square.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_surrounded_wall/hole_first.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_surrounded_wall/hole_last.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_surrounded_wall/hole_last_not_newline.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_surrounded_wall/hole_side_first.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/check_surrounded_wall/hole_side_last.ber
	valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/crossing_wall/column.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/crossing_wall/not.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/crossing_wall/row.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/failed_read/empty.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/not_get_collect/surrounded_wall.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/not_get_collect/surrounded_enemy.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/success/no_new_line_last.ber
	@# valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./$@ ./maps/success/one_new_line_last.ber

test_overflow: $(OBJS)
	$(CC) -g -fsanitize=address -o $@ $^ -L$(MLX_DIR) $(MLX_LIB) -L$(LIBFT_DIR) $(LIBFT_LIB)
	./test_overflow ./maps/success/one_new_line_last.ber

test_open_map_fd:
	$(CC) $(CFLAGS) -c $(INCLUDE) $(MLX_INCLUDE) $(LIBFT_INCLUDE) ./srcs/open_map_fd.c -o ./objs/open_map_fd.o
	$(CC) $(CFLAGS) -c $(INCLUDE) $(MLX_INCLUDE) $(LIBFT_INCLUDE) ./srcs/exit_write_error_message.c -o ./objs/exit_write_error_message.o
	$(CC) $(CFLAGS) -c $(INCLUDE) $(MLX_INCLUDE) $(LIBFT_INCLUDE) ./srcs/exit_perror.c -o ./objs/exit_perror.o
	$(CC) -g -fsanitize=address -o $@ ./objs/open_map_fd.o ./objs/exit_write_error_message.o ./objs/exit_perror.o -L$(MLX_DIR) $(MLX_LIB) -L$(LIBFT_DIR) $(LIBFT_LIB)

norm:
	@norminette -v
	@norminette ./libft ./srcs ./includes
