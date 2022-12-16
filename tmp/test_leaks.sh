#/bin/zsh

valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/sample.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_elements/only_wall_height_two.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_elements/only_wall_width_two.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_extra_newline/first.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_extra_newline/in_map.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_extra_newline/last.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_extra_newline/only.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_multiple_E.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_multiple_P.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_not_0.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_not_C.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_not_E.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_not_P.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_map_elements/has_wrong_element.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/large_square.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/long_first.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/long_in_map.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/long_last.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/short_first.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/short_in_map.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/short_last.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_rectangular/small_square.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_surrounded_wall/hole_first.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_surrounded_wall/hole_last.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_surrounded_wall/hole_last_not_newline.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_surrounded_wall/hole_side_first.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/check_surrounded_wall/hole_side_last.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/crossing_wall/column.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/crossing_wall/not.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/crossing_wall/row.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/failed_read/empty.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/not_get_collect/surrounded_wall.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/not_get_collect/surrounded_enemy.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/success/no_new_line_last.ber
valgrind --leak-check=full --leak-resolution=high --show-reachable=yes ./test_leaks ./maps/success/one_new_line_last.ber

