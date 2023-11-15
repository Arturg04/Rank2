/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:37:10 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 11:27:54 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

t_so_long	*init_game(void)
{
	t_so_long	*game;

	game = (t_so_long *)malloc(sizeof(t_so_long));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (NULL);
	game->win = NULL;
	game->map = NULL;
	game->enemy = NULL;
	game->col = 0;
	game->moves = 0;
	return (game);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->col = 0;
	map->exit = 0;
	map->width = 0;
	map->heigth = 0;
	map->player = 0;
	return (map);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = 0;
	player->y = 0;
	player->img = NULL;
	return (player);
}

t_enemy	**init_enemy(int num)
{
	t_enemy	*enemy;

	enemy = (t_enemy **)malloc(sizeof(t_enemy *) * num);
	if (!enemy)
		return (NULL);
	enemy->x = 0;
	enemy->y = 0;
	enemy->img = NULL;
	return (enemy);
}

t_exit	*init_exit(void)
{
	t_exit	*exit;

	exit = (t_exit *)malloc(sizeof(t_exit));
	if (!exit)
		return (NULL);
	exit->x = 0;
	exit->y = 0;
	return (exit);
}

