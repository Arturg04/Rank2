/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:29:33 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 12:01:43 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	map_assets(t_so_long *game, int i)
{
	t_map	*map;

	map = game->map;
	map->wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &i, &i);
	map->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm", &i, &i);
}

void	render_map(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->heigth)
	{
		j = 0;
		while (j < game->map->width)
		{
			//draw_img(game, game->floor, j, i);
			if (game->map->map[i][j] == '1')
				//draw_img(game, game->wall, j, i);
			if (game->map->map[i][j] == 'C')
				//draw_img(game, game->collect, j, i);
			if (game->map->map[i][j] == 'E')
				//draw_img(game, game->exit, j, i);
			j++;
		}
		i++;
	}
}

void	render_player(t_so_long *game, int i, int j)
{
	//draw_img(game, game->floor, j, i);
	//draw_img(game, game->player, game->player_x, game->player_y);
}

void	render_enemy(t_so_long *game, int i, int j)
{
	//draw_img(game, game->floor, j, i);
	//draw_img(game, game->enemy, game->enemy_x, game->enemy_y);
}
