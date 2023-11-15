/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:36 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 15:48:44 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	get_player_assets(t_so_long *game)
{
	t_player	*player;

	player->img = malloc(sizeof(void *) * 17);
	if (!player->img)
		return ;
	player->img[0] = get_img_png(game, "./assets/cat/cat_0.png", 65);
	player->img[1] = get_img_png(game, "./assets/cat/cat_1.png", 65);
	player->img[2] = get_img_png(game, "./assets/cat/cat_2.png", 65);
	player->img[3] = get_img_png(game, "./assets/cat/cat_3.png", 65);
	player->img[4] = get_img_png(game, "./assets/cat/cat_4.png", 65);
	player->img[5] = get_img_png(game, "./assets/cat/cat_5.png", 65);
	player->img[6] = get_img_png(game, "./assets/cat/cat_6.png", 65);
	player->img[7] = get_img_png(game, "./assets/cat/cat_7.png", 65);
	player->img[8] = get_img_png(game, "./assets/cat/cat_8.png", 65);
	player->img[9] = get_img_png(game, "./assets/cat/cat_9.png", 65);
	player->img[10] = get_img_png(game, "./assets/cat/cat_10.png", 65);
	player->img[11] = get_img_png(game, "./assets/cat/cat_11.png", 65);
	player->img[12] = get_img_png(game, "./assets/cat/cat_12.png", 65);
	player->img[13] = get_img_png(game, "./assets/cat/cat_13.png", 65);
	player->img[14] = get_img_png(game, "./assets/cat/cat_14.png", 65);
	player->img[15] = get_img_png(game, "./assets/cat/cat_15.png", 65);
	player->img[16] = NULL;
}

void	free_player(t_player *player)
{
	if (player->img)
		free(player->img);
	free(player);
}
