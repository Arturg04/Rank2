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

int	render(t_so_long *game)
{
	static int time;
	int	i;
	int	j;

	i = -1;
	if (time++ < 100)
		return (0);
	time = 0;
	mlx_clear_window(game->mlx, game->win);
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->xpm[0], 100 * j, 100 * i);
			if (game->map->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->xpm[2], 100 * j, 100 * i);
			else if (game->map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->xpm[1], 100 * j, 100 * i);
			else if (game->map->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->xpm[4], 100 * j, 100 * i);
			else if (game->map->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->xpm[3], 100 * j, 100 * i);
		}
	}
	return (0);
}

void	load_all_xpms(t_so_long *game)
{
	int	i;

	i = 100;
	game->xpm = malloc(sizeof(void *) * 6);
	game->xpm[0] = mlx_xpm_file_to_image(game->mlx, "./assets/other/other_0.xpm", &i, &i);
	game->xpm[1] = mlx_xpm_file_to_image(game->mlx, "./assets/other/other_1.xpm", &i, &i);
	game->xpm[2] = mlx_xpm_file_to_image(game->mlx, "./assets/coin/coin_0.xpm", &i, &i);
	game->xpm[3] = mlx_xpm_file_to_image(game->mlx, "./assets/gate/gate_0.xpm", &i, &i);
	game->xpm[4] = mlx_xpm_file_to_image(game->mlx, "./assets/cat/cat_0.xpm", &i, &i);
	game->xpm[5] = NULL;
}

int	main(int ac, char **av)
{
	t_so_long	*game;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_so_long));
	parser(av[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 100 * game->map->width, 100 * game->map->heigth, "so_long");
	game->moves = 0;
	game->col = 0;
	load_all_xpms(game);
	render(game);
	set_keys(game);
	printf("Moves: 0\n");
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}