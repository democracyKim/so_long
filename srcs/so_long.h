/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:15:50 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 12:59:19 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>

# define MOVE_THRESHOLD 10

enum e_definition
{
	ERROR = -1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	KEY_DOWN = 1,
	KEY_UP = 13,
	KEY_ESC = 53,
};

typedef struct game_type
{
	char	**map;
	int		width;
	int		height;
	int		num_cepm[4];
	int		player_position[2];
	void	*mlx;
	void	*dino_advanture;
	void	*dino_left[15];
	void	*dino_right[15];
	void	*enemy[2];
	void	*wall;
	void	*road;
	void	*item;
	void	*spellbook;
	int		left;
	int		moving_count;
	int		game_start;
}	t_game;

int		map_init(t_game *map_info, char *map_file);
void	so_long(char *map_file);
int		check_map(t_game *map_info);
int		check_route(t_game *map_info, int player_pos[2]);
void	open_image(t_game *image);
int		display_footprint(t_game *map_info);
void	display_map(t_game *map_info);
void	error_exit(char *msg);
void	print_messages(char *msg);
int		move_player(int keycode, void *param);
void	move_enemy(t_game *map_info);
int		handle_close_button(void *param);
void	free_array(char **array, int size);
void	finish_game(t_game *map_info);
void	load_dino_sprites(t_game *map_info, int x, int y);
void	put_image(t_game *map_info, int x, int y, void *img);
int		find_enemy(t_game *game, int start_x, \
			int start_y, int enemy_position[2]);
#endif