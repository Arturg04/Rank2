/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 08:47:55 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/12 14:22:03 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = -1;
		while (map->map[++i] && map->map[i] != NULL)
		{
			if (map->map[i])
				free(map->map[i]);
		}
		if (map->map)
			free(map->map);
	}
	if (map)
		free(map);
}

void	call_error(t_so_long *game)
{
	if (game->map)
		free_map(game->map);
	if (game)
		free(game);
	write(2, "Error\n", 6);
	exit(0);
}

int	end_game(t_so_long *game)
{
	int	i;

	i = -1;
	mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map);
	while (game->xpm[++i])
		mlx_destroy_image(game->mlx, game->xpm[i]);
	if (game->xpm)
		free(game->xpm);
	if (game)
		free(game);
	exit(0);
	return (0);
}

void	print_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		printf("%s\n", map->map[i]);
}

char	*joint_free(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	i = -1;
	while (str1[++i])
		str[i] = str1[i];
	j = -1;
	while (str2[++j])
		str[i + j] = str2[j];
	str[i + j] = '\0';
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (str);
}
