/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:52 by minkim3           #+#    #+#             */
/*   Updated: 2023/02/23 13:07:11 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*xpm_to_image(t_game *image, char *address)
{
	int		width;
	int		height;
	void	*put_image;

	put_image = mlx_xpm_file_to_image(image->mlx, address, &width, &height);
	if (put_image == NULL)
		error_exit("error : cannot open_image\n");
	return (put_image);
}

static void	open_dino_right(t_game *image)
{
	image->dino_right[0] = xpm_to_image(image, "./images/dino/right/1.xpm");
	image->dino_right[1] = xpm_to_image(image, "./images/dino/right/2.xpm");
	image->dino_right[2] = xpm_to_image(image, "./images/dino/right/3.xpm");
	image->dino_right[3] = xpm_to_image(image, "./images/dino/right/4.xpm");
	image->dino_right[4] = xpm_to_image(image, "./images/dino/right/5.xpm");
	image->dino_right[5] = xpm_to_image(image, "./images/dino/right/6.xpm");
	image->dino_right[6] = xpm_to_image(image, "./images/dino/right/7.xpm");
	image->dino_right[7] = xpm_to_image(image, "./images/dino/right/8.xpm");
	image->dino_right[8] = xpm_to_image(image, "./images/dino/right/9.xpm");
	image->dino_right[9] = xpm_to_image(image, "./images/dino/right/10.xpm");
	image->dino_right[10] = xpm_to_image(image, "./images/dino/right/11.xpm");
	image->dino_right[11] = xpm_to_image(image, "./images/dino/right/12.xpm");
	image->dino_right[12] = xpm_to_image(image, "./images/dino/right/13.xpm");
	image->dino_right[13] = xpm_to_image(image, "./images/dino/right/14.xpm");
	image->dino_right[14] = xpm_to_image(image, "./images/dino/right/15.xpm");
}

static void	open_dino_left(t_game *image)
{
	image->dino_left[0] = xpm_to_image(image, "./images/dino/left/1.xpm");
	image->dino_left[1] = xpm_to_image(image, "./images/dino/left/2.xpm");
	image->dino_left[2] = xpm_to_image(image, "./images/dino/left/3.xpm");
	image->dino_left[3] = xpm_to_image(image, "./images/dino/left/4.xpm");
	image->dino_left[4] = xpm_to_image(image, "./images/dino/left/5.xpm");
	image->dino_left[5] = xpm_to_image(image, "./images/dino/left/6.xpm");
	image->dino_left[6] = xpm_to_image(image, "./images/dino/left/7.xpm");
	image->dino_left[7] = xpm_to_image(image, "./images/dino/left/8.xpm");
	image->dino_left[8] = xpm_to_image(image, "./images/dino/left/9.xpm");
	image->dino_left[9] = xpm_to_image(image, "./images/dino/left/10.xpm");
	image->dino_left[10] = xpm_to_image(image, "./images/dino/left/11.xpm");
	image->dino_left[11] = xpm_to_image(image, "./images/dino/left/12.xpm");
	image->dino_left[12] = xpm_to_image(image, "./images/dino/left/13.xpm");
	image->dino_left[13] = xpm_to_image(image, "./images/dino/left/14.xpm");
	image->dino_left[14] = xpm_to_image(image, "./images/dino/left/15.xpm");
}

static void	open_components(t_game *image)
{
	image->enemy[0] = xpm_to_image(image, "./images/enemy/1.xpm");
	image->enemy[1] = xpm_to_image(image, "./images/enemy/2.xpm");
	image->item = xpm_to_image(image, "./images/item.xpm");
	image->road = xpm_to_image(image, "./images/road.xpm");
	image->spellbook = xpm_to_image(image, "./images/spellbook.xpm");
	image->wall = xpm_to_image(image, "./images/wall.xpm");
}

void	open_image(t_game *image)
{
	image->mlx = mlx_init();
	image->dino_advanture = mlx_new_window(image->mlx, \
		image->width * 64, image->height * 64, "dino_advanture");
	open_dino_right(image);
	open_dino_left(image);
	open_components(image);
}
