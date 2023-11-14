/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:06:44 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/12 15:49:32 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_pos(t_so_long *game, int i, int j)
{
	if (game->map->map[game->player_y][game->player_x] == '1')
	{
		game->player_x = j;
		game->player_y = i;
		return ;
	}
	if (game->map->map[game->player_y][game->player_x] == 'C')
		game->col++;
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	if (game->map->col == game->col
		&& game->player_y == game->exit_y
		&& game->player_x == game->exit_x)
	{
		write(1, "You won the game in ", 20);
		ft_putnbr_fd(game->moves, 1);
		write(1, " moves\n", 7);
		end_game(game);
	}
	game->map->map[game->player_y][game->player_x] = 'P';
	game->map->map[i][j] = '0';
}

void	move_up(t_so_long *game)
{
	game->player_x = game->player_x;
	game->player_y = game->player_y - 1;
	player_pos(game, game->player_y + 1, game->player_x);
}

void	move_down(t_so_long *game)
{
	game->player_x = game->player_x;
	game->player_y = game->player_y + 1;
	player_pos(game, game->player_y - 1, game->player_x);

}

void	move_left(t_so_long *game)
{
	game->player_x = game->player_x - 1;
	game->player_y = game->player_y;
	player_pos(game, game->player_y, game->player_x + 1);

}

void	move_right(t_so_long *game)
{
	game->player_x = game->player_x + 1;
	game->player_y = game->player_y;
	player_pos(game, game->player_y, game->player_x - 1);
}
