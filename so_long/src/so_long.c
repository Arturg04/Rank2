/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:13:20 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/12 16:26:20 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	image(void *mlx, void *win, void *img, int x, int y)
{
	int	i;

	i = 100;
	mlx_put_image_to_window(mlx, win, img, x * i, y * i);
}

int	render(t_so_long *game)
{
	static int	time;
	int			i;
	int			j;

	i = -1;
	if (time++ < 100)
		return (0);
	time = 0;
	while (game->map->map[++i] && i < game->map->heigth)
	{
		j = -1;
		while (game->map->map[i][++j] && j < game->map->width)
		{
			image(game->mlx, game->win, game->xpm[0], j, i);
			if (game->map->map[i][j] == 'C')
				image(game->mlx, game->win, game->xpm[2], j, i);
			if (game->map->map[i][j] == '1')
				image(game->mlx, game->win, game->xpm[1], j, i);
			if (i == game->exit_y && j == game->exit_x)
				image(game->mlx, game->win, game->xpm[3], j, i);
			if (game->map->map[i][j] == 'P')
				image(game->mlx, game->win, game->xpm[4], j, i);
		}
	}
	return (0);
}

void	load_all_xpms(t_so_long *game)
{
	int	i;

	i = 100;
	game->xpm = malloc(sizeof(void *) * 6);
	game->xpm[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/other/other_0.xpm", &i, &i);
	game->xpm[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/other/other_1.xpm", &i, &i);
	game->xpm[2] = mlx_xpm_file_to_image(game->mlx,
			"./assets/coin/coin_0.xpm", &i, &i);
	game->xpm[3] = mlx_xpm_file_to_image(game->mlx,
			"./assets/gate/gate_0.xpm", &i, &i);
	game->xpm[4] = mlx_xpm_file_to_image(game->mlx,
			"./assets/cat/cat_0.xpm", &i, &i);
	game->xpm[5] = NULL;
}

int	main(int ac, char **av)
{
	t_so_long	*game;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_so_long));
	parser(av[1], game);
	fludfill_coin(game, game->player_y, game->player_x);
	if (game->col != game->map->col)
		call_error(game);
	free_map(game->map);
	parser(av[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 100 * game->map->width,
			100 * game->map->heigth, "so_long");
	game->moves = 0;
	game->col = 0;
	load_all_xpms(game);
	render(game);
	set_keys(game);
	printf("Moves: 0\n");
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}
