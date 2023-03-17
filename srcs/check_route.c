/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:43 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 13:14:03 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	dfs(char **map, char collect, int x, int y)
{
	int	count;

	count = 0;
	if (collect == 'C')
		if (map[y][x] == 'E')
			return (0);
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (0);
	if (map[y][x] != 'x')
	{
		if (map[y][x] == collect)
		{
			map[y][x] = 'x';
			count++;
		}
		map[y][x] = 'x';
		count += dfs(map, collect, x + 1, y);
		count += dfs(map, collect, x, y + 1);
		count += dfs(map, collect, x - 1, y);
		count += dfs(map, collect, x, y - 1);
	}
	return (count);
}

static void	map_duplicate(char **map, int height, int width, char ***map_dup)
{
	int	i;
	int	j;

	*map_dup = malloc(height * sizeof(char *));
	if (*map_dup == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		(*map_dup)[i] = malloc(width * sizeof(char));
		if ((*map_dup)[i] == NULL)
		{
			free_array(*map_dup, i);
			return ;
		}
		j = 0;
		while (j < width)
		{
			(*map_dup)[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

int	check_route(t_game *map_info, int player_pos[2])
{
	int		collect;
	int		exit;
	char	**map_dup;

	collect = 0;
	exit = 0;
	map_dup = NULL;
	map_duplicate(map_info->map, map_info->height, map_info->width, &map_dup);
	if (map_dup == NULL)
		return (ERROR);
	collect += dfs(map_dup, 'C', player_pos[1], player_pos[0]);
	free_array(map_dup, map_info->height);
	map_duplicate(map_info->map, map_info->height, map_info->width, &map_dup);
	exit += dfs(map_dup, 'E', player_pos[1], player_pos[0]);
	free_array(map_dup, map_info->height);
	if (collect != map_info->num_cepm[0] || exit != 1)
		return (ERROR);
	return (0);
}
