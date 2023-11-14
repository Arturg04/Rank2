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

static void	check_name(char	*file, t_so_long *game)
{
	char	*ext;

	ext = ft_strchr(file, '.');
	if (!ext)
		call_error(game);
	while (ft_strchr(ext + 1, '.'))
		ext = ft_strchr(ext + 1, '.');
	if (ft_strncmp(ext, ".ber", ft_strlen(ext)))
		call_error(game);
}

static t_map	*to_array(char	*str)
{
	t_map	*map;
	int		i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') || str[0] == '\n')
			return (free(str), NULL);
	}
	map = malloc(sizeof(t_map) * 1);
	map->map = ft_split(str, '\n');
	map->heigth = 0;
	if (!*(map->map))
		return (free(str), free_map(map), NULL);
	map->width = (int)ft_strlen(map->map[map->heigth]);
	while (map->map[map->heigth])
	{
		if (map->width != (int)ft_strlen(map->map[map->heigth]))
			return (free(str), free_map(map), NULL);
		map->heigth++;
	}
	if (map->heigth < 3 || map->width < 3)
		return (free(str), free_map(map), NULL);
	return (free(str), map);
}

static void	check_map2(t_so_long *game, int i, int j)
{
	t_map	*map;

	map = game->map;
	if ((i == 0 && map->map[i][j] != '1')
			|| (i == map->heigth - 1 && map->map[i][j] != '1')
			|| (j == 0 && map->map[i][j] != '1')
			|| (j == map->width && map->map[i][j] != '1'))
		call_error(game);
	if (game->map->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		game->map->player++;
		game->col = 0;
	}
	else if (map->map[i][j] == 'C')
		map->col++;
	else if (map->map[i][j] == 'E')
	{
		game->exit_x = j;
		game->exit_y = i;
		map->exit++;
	}
	else if (map->map[i][j] != '1' && map->map[i][j] != '0')
		call_error(game);
}

static void	check_map(t_so_long *game)
{
	int		i;
	int		j;
	t_map	*map;

	map = game->map;
	i = -1;
	map->player = 0;
	map->exit = 0;
	map->col = 0;
	if (!*map->map)
		call_error(game);
	while (map->map[++i] && i < map->heigth - 1)
	{
		j = -1;
		while (map->map[i][++j] && j < map->width - 1)
			check_map2(game, i, j);
	}
	game->col = 0;
	if (map->player != 1 || map->exit != 1 || map->col < 1)
		call_error(game);
	if (!fludfill(game, game->player_y, game->player_x))
		call_error(game);
}

void	parser(char *file, t_so_long *game)
{
	int		fd;
	char	*buf;
	char	*buffer;
	int		bytes;

	check_name(file, game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		call_error(game);
	buffer = ft_calloc(sizeof(char), 1);
	bytes = 1;
	while (bytes > 0)
	{
		buf = malloc(1024 + 1);
		bytes = read(fd, buf, 1024);
		buf[bytes] = '\0';
		buffer = joint_free(buffer, buf);
	}
	if (!buffer)
		call_error(game);
	game->map = to_array(buffer);
	if (!game->map)
		call_error(game);
	check_map(game);
	close(fd);
}
