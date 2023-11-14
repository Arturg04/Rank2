/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:14:16 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/12 16:24:09 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <X11/X.h>
# include "keys.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"

typedef struct s_map
{
	int		width;
	int		heigth;
	int		col;
	int		player;
	int		exit;
	char	**map;
}			t_map;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	t_map		*map;
	void		**xpm;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			col;
	int			moves;
}			t_so_long;

//---------------MLX

//---------------Window

//---------------Images

//---------------Moves
void	move_up(t_so_long *game);
void	move_down(t_so_long *game);
void	move_left(t_so_long *game);
void	move_right(t_so_long *game);

//---------------Utils
void	call_error(t_so_long *game);
void	free_map(t_map *map);
int		end_game(t_so_long *game);
char	*joint_free(char *str1, char *str2);

//---------------Parser
void	parser(char *file, t_so_long *game);
int		fludfill(t_so_long *game, int i, int j);
void	fludfill_coin(t_so_long *game, int i, int j);

//---------------Keys
void	set_keys(t_so_long *game);
int		key_press(int keycode, t_so_long *game);

//---------------Player

#endif
