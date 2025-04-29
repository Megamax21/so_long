/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 03:55:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/29 18:32:52 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		p_x;
	int		p_y;
	int		p_moves;
	int		e_x;
	int		e_y;
	int		collectibles;
	int		exit_state;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit_0;
	void	*img_exit_1;
}				t_data;

char		**ft_ber_to_array(char *map_path, t_data *data);
char		**ft_convert_list_to_array(t_list *list, t_data *data);
void		ft_error(const char *msg);
int			ft_get_map_h(char **map);
int			ft_get_map_w(char **map);
void		ft_flood_fill(char **map, int x, int y);
char		**ft_dup_map(char **map, int free_map);
t_data		*ft_new_data(void	*mlx);
void		ft_put_img(t_data *data, int i, int j);
void		ft_draw_map(t_data *myDatas);
void		*ft_get_img(char c, t_data *data);
int			ft_close_window(t_data *data);
int			ft_key_press(int keycode, t_data *data);
void		ft_assign_player_pos(t_data **data, int w, int h);
int			ft_count_tile(char **map, char tile);
void		ft_assign_exit_pos(t_data *data);
void		ft_free_char_array(char **array);
void		ft_free_not_rectangle(t_data *data, char **arr, t_list *list);

/* Map Parsing */
int			ft_check_if_ber(char *name);
void		ft_verify_map(t_data **data);
void		ft_verify_walls(t_data *data, int w, int h);
void		ft_check_map_after_flood(t_data *data);
void		ft_check_player_on_map(t_data *data, int w, int h);
int			ft_check_collectibles_on_map(t_data *data);
int			ft_check_exit_on_map(t_data *data);
void		ft_check_strange_char(t_data *data, int w, int h);

/* Player Movements */
int			ft_move_up(t_data **data);
int			ft_move_left(t_data **data);
int			ft_move_down(t_data **data);
int			ft_move_right(t_data **data);
