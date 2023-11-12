/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:49:44 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/12 16:24:05 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_name(char	*file)
{
	char	*ext;

	ext = ft_strchr(file, '.');
	while (ft_strchr(ext + 1, '.'))
		ext = ft_strchr(ext + 1, '.');
	return (!ft_strncmp(ext, ".ber", ft_strlen(ext)));
}

static t_map	*to_array(char	*str)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map) * 1);
	map->map = ft_split(str, '\n');
	i = -1;
	free(str);
	map->heigth = 0;
	if (!*(map->map))
		return (free_map(map), NULL);
	map->width = (int)ft_strlen(map->map[map->heigth]);
	while (map->map[map->heigth])
	{
		if (map->width != (int)ft_strlen(map->map[map->heigth]))
			return (free_map(map), NULL);
		map->heigth++;
	}
	if (map->heigth < 3 || map->width < 3)
		return (free_map(map), NULL);
	return (map);
}

static void check_map2(t_so_long *game, int i, int j)
{
	if (game->map->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		game->map->player++;
		if (!fludfill(game, i, j))
			call_error(game);
	}
	if (game->map->map[i][j] == 'C')
		game->map->collectibles++;
	if (game->map->map[i][j] == 'E')
		game->map->exit++;
	if (game->map->player > 1 || game->map->exit > 1)
		call_error(game);
}

static void	check_map(t_so_long *game)
{
	int	i;
	int	j;
	t_map	*map;

	map = game->map;
	i = -1;
	map->player = 0;
	map->exit = 0;
	map->collectibles = 0;
	if (!*map->map)
		call_error(game);
	while (map->map[++i] && i < map->heigth - 1)
	{
		j = -1;
		while (map->map[i][++j] && j < map->width - 1)
		{
			if ((i == 0 && map->map[i][j] != '1')
					|| (i == map->heigth - 1 && map->map[i][j] != '1')
					|| (j == 0 && map->map[i][j] != '1')
					|| (j == map->width && map->map[i][j] != '1'))
					call_error(game);
			check_map2(game, i, j);
		}
	}
}

void	parser(char *file, t_so_long *game)
{
	int		fd;
	char	*buf;
	char	*buffer;
	int		bytes;

	if (!check_name(file))
		call_error(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		call_error(game);
	buffer = ft_calloc(sizeof(char), 1);
	buf = malloc(1024 + 1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, 1024);
		buf[bytes] = '\0';
		buffer = joint_free(buffer, buf);
		buf = malloc(1024 + 1);
	}
	if (buf)
		free(buf);
	if (!buffer)
		call_error(game);
	game->map = to_array(buffer);
	if (!game->map)
		call_error(game);
	check_map(game);
}
