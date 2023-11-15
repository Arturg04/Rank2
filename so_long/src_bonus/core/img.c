/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:15:33 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 11:52:28 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	*get_img_xpm(t_so_long *game, char *path, int i)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &i, &i);
	if (!img)
		return (NULL);
	return (img);
}

void	*get_img_png(t_so_long *game, char *path, int i)
{
	void	*img;

	img = mlx_png_file_to_image(game->mlx, path, &i, &i);
	if (!img)
		return (NULL);
	return (img);
}

void	draw_img(t_so_long *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 65, y * 65);
}
