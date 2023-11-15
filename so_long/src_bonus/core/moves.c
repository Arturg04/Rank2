/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:06:44 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/14 23:28:40 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_up(t_so_long *game)
{
	t_player	*player;

	player = game->player;
	player->x = player->x;
	player->y = player->y - 1;
	player_pos(game, player->y + 1, player->x);
}

void	move_down(t_so_long *game)
{
	t_player	*player;

	player = game->player;
	player->x = player->x;
	player->y = player->y + 1;
	player_pos(game, player->y - 1, player->x);
}

void	move_left(t_so_long *game)
{
	t_player	*player;

	player = game->player;
	player->x = player->x - 1;
	player->y = player->y;
	player_pos(game, player->y, player->x + 1);
}

void	move_right(t_so_long *game)
{
	t_player	*player;

	player = game->player;
	player->x = player->x + 1;
	player->y = player->y;
	player_pos(game, player->y, player->x - 1);
}
