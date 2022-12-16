/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 03:18:12 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/12/16 17:56:26 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_GAME_H
# define END_GAME_H

# include "so_long.h"

typedef struct s_player_position	t_player_position;
typedef struct s_map_info			t_map_info;
typedef struct s_image				t_image;
typedef struct s_player				t_player;
typedef struct s_map_part_images	t_map_part_images;
typedef struct s_game_info			t_game_info;

void	destroy_window(t_game_info *info);
void	destroy_player_images(t_game_info *info);
void	destroy_map_parts(t_game_info *info);
void	destroy_display(t_game_info *info);
#endif
