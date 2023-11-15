/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:58:26 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/14 23:24:37 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	set_keys(t_so_long *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, &end_game, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, &end_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &key_press, game);
}

int	key_press(int keycode, t_so_long *game)
{
	if (keycode == KEY_ESCAPE)
		end_game(game);
	else if (keycode == KEY_W || keycode == ARROW_UP)
		move_up(game);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_left(game);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_down(game);
	else if (keycode == KEY_D || keycode == ARROW_RIGTH)
		move_right(game);
	return (0);
}
