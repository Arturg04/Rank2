/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:53:19 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 11:59:48 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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
	map = init_map();
	map->map = ft_split(str, '\n');
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
