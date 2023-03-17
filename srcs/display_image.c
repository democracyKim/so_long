/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:45 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 09:28:13 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *map_info, int x, int y, void *img)
{
	mlx_put_image_to_window(map_info->mlx, \
		map_info->dino_advanture, img, x * 64, y * 64);
}

static void	display_map_tiles(t_game *map_info, int x, int y)
{
	if (map_info->map[y][x] == '1')
		put_image(map_info, x, y, map_info->wall);
	else
		put_image(map_info, x, y, map_info->road);
	if (map_info->map[y][x] == 'C')
		put_image(map_info, x, y, map_info->item);
	else if (map_info->map[y][x] == 'E')
		put_image(map_info, x, y, map_info->spellbook);
	else if (map_info->map[y][x] == 'M' && (rand() % 5 == 0))
		put_image(map_info, x, y, map_info->enemy[(x + y) % 2]);
	else if (map_info->map[y][x] == 'M')
		put_image(map_info, x, y, map_info->enemy[(x + y) % 2]);
	else if (map_info->map[y][x] == 'P')
		put_image(map_info, x, y, map_info->dino_right[0]);
}

void	display_map(t_game *map_info)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			display_map_tiles(map_info, x, y);
			x++;
		}
		y++;
	}
}

int	display_footprint(t_game *map_info)
{
	char		*moving_count_str;

	moving_count_str = ft_itoa(map_info->moving_count);
	put_image(map_info, 0, 0, map_info->wall);
	mlx_string_put(map_info->mlx, map_info->dino_advanture, \
					20, 20, 0x0000FF, moving_count_str);
	free(moving_count_str);
	return (0);
}

void	load_dino_sprites(t_game *map_info, int x, int y)
{
	static int	frame = 0;
	static int	delay = 3;
	void		*dino;

	if (map_info->left == 1)
		dino = map_info->dino_left[frame / delay % 15];
	else
		dino = map_info->dino_right[frame / delay % 15];
	put_image(map_info, x, y, map_info->road);
	put_image(map_info, x, y, dino);
	frame++;
}
