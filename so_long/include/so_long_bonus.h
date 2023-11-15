/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-pinh <ade-pinh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 02:14:16 by ade-pinh          #+#    #+#             */
/*   Updated: 2023/11/15 16:49:36 by ade-pinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <X11/X.h>
# include "keys.h"
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"

# define IMG_W 64
# define IMG_H 64

typedef struct s_player
{
	int		x;
	int		y;
	void	**img;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	void	**img;
}	t_enemy;

typedef struct s_exit
{
	int		x;
	int		y;
}	t_exit;

typedef struct s_map
{
	int		width;
	int		heigth;
	int		col;
	int		player;
	int		exit;
	void 	*wall;
	void	*floor;
	char	**map;
}	t_map;

typedef struct s_so_long
{
	int			col;
	int			moves;
	void		*mlx;
	void		*win;
	void		**xpm;
	t_map		*map;
	t_player	*player;
	t_enemy		**enemy;
	t_exit		*exit;
}			t_so_long;

t_so_long	*init_game(void);
t_player	*init_player(void);
t_enemy		**init_enemy(int num);
t_exit		*init_exit(void);
t_exit		*init_exit(void);

void		*get_img_xpm(t_so_long *game, char *path, int size);
void		*get_img_png(t_so_long *game, char *path, int size);
void		draw_img(t_so_long *game, void *img, int x, int y);

//---------------MLX

//---------------Window

//---------------Images

//---------------Moves
void		move_up(t_so_long *game);
void		move_down(t_so_long *game);
void		move_left(t_so_long *game);
void		move_right(t_so_long *game);

//---------------Utils
void		call_error(t_so_long *game);
void		free_map(t_map *map);
int			end_game(t_so_long *game);
char		*joint_free(char *str1, char *str2);

//---------------Parser
void		parser(char *file, t_so_long *game);
int			fludfill(t_so_long *game, int i, int j);
void		fludfill_coin(t_so_long *game, int i, int j);

//---------------Keys
void		set_keys(t_so_long *game);
int			key_press(int keycode, t_so_long *game);

//---------------Player

#endif
