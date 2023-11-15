/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:36:15 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 15:48:42 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	get_enemy_assets(t_so_long *game)
{
	t_enemy	*enemy;

	enemy->img = malloc(sizeof(void *) * 17);
	if (!enemy->img)
		return ;
	enemy->img[0] = get_img_png(game, "./assets/monster/monster_0.png", 65);
	enemy->img[1] = get_img_png(game, "./assets/monster/monster_1.png", 65);
	enemy->img[2] = get_img_png(game, "./assets/monster/monster_2.png", 65);
	enemy->img[3] = get_img_png(game, "./assets/monster/monster_3.png", 65);
	enemy->img[4] = get_img_png(game, "./assets/monster/monster_4.png", 65);
	enemy->img[5] = get_img_png(game, "./assets/monster/monster_5.png", 65);
	enemy->img[6] = get_img_png(game, "./assets/monster/monster_6.png", 65);
	enemy->img[7] = get_img_png(game, "./assets/monster/monster_7.png", 65);
	enemy->img[8] = get_img_png(game, "./assets/monster/monster_8.png", 65);
	enemy->img[9] = get_img_png(game, "./assets/monster/monster_9.png", 65);
	enemy->img[10] = get_img_png(game, "./assets/monster/monster_10.png", 65);
	enemy->img[11] = get_img_png(game, "./assets/monster/monster_11.png", 65);
	enemy->img[12] = get_img_png(game, "./assets/monster/monster_12.png", 65);
	enemy->img[13] = get_img_png(game, "./assets/monster/monster_13.png", 65);
	enemy->img[14] = get_img_png(game, "./assets/monster/monster_14.png", 65);
	enemy->img[15] = get_img_png(game, "./assets/monster/monster_15.png", 65);
	enemy->img[16] = NULL;
}

void	free_map(t_map *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	free(game);
}
