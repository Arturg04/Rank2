/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:23:21 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/12 15:14:37 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	fludfill(t_so_long *game, int i, int j)
{
	char	c;
	int		k;

	k = 0;
	if (game->map->map[i][j] == 'E')
		return (1);
	if (game->map->map[i][j] != '1')
	{
		c = game->map->map[i][j];
		game->map->map[i][j] = '1';
		if (i > 0 && !k)
			k = fludfill(game, i - 1, j);
		if (i < game->map->heigth - 1 && !k)
			k = fludfill(game, i + 1, j);
		if (j > 0 && !k)
			k = fludfill(game, i, j - 1);
		if (j < game->map->width - 1 && !k)
			k = fludfill(game, i, j + 1);
		game->map->map[i][j] = c;
	}
	return (k);
}

void	fludfill_coin(t_so_long *game, int i, int j)
{
	if (game->map->map[i][j] == 'C')
		game->col++;
	if (game->map->map[i][j] != '1')
	{
		game->map->map[i][j] = '1';
		if (i > 0 && game->col != game->map->col)
			fludfill_coin(game, i - 1, j);
		if (i < game->map->heigth - 1 && game->col != game->map->col)
			fludfill_coin(game, i + 1, j);
		if (j > 0 && game->col != game->map->col)
			fludfill_coin(game, i, j - 1);
		if (j < game->map->width - 1 && game->col != game->map->col)
			fludfill_coin(game, i, j + 1);
	}
}
