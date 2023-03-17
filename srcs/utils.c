/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:52 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 13:03:21 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(2, msg, len);
	exit(0);
}

void	print_messages(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(1, msg, len);
}

int	handle_close_button(void *param)
{
	(void)param;
	print_messages("You clicked close button!\n");
	exit(0);
}

void	free_array(char **array, int size)
{
	while (size--)
		free(array[size]);
	free(array);
}

void	finish_game(t_game *map_info)
{
	free_array(map_info->map, map_info->height);
	free(map_info);
	exit(0);
}
