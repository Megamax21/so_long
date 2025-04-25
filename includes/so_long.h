#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
	char	**map;
}				t_data;

void		ft_put_image(void *mlx, void *window, char *img_path, int x, int y);
char		**ft_ber_to_array(char *map_path);
char		**ft_convert_list_to_array(t_list *list);
void		ft_error(const char *msg);
void		ft_verify_map(char **map_arr);
void		ft_verify_walls(char **map_arr, int w, int h);
int			ft_get_map_h(char **map);
int			ft_get_map_w(char **map);
void		ft_flood_fill(char **map, int x, int y);
char		**ft_dup_map(char **map);
void		ft_check_map_after_flood(char **map, int w, int h);
void		ft_check_player_on_map(char **map_arr, int w, int h);
int			ft_check_collectibles_on_map(char **map_arr, int w, int h, int is_flood);
int			ft_check_exit_on_map(char **map_arr, int w, int h, int is_flood);
void		ft_check_strange_char(char **map_arr, int w, int h);
t_data		*ft_new_data(void	*mlx);
void		ft_put_square(t_data *data, int x, int y, int color);
void		ft_draw_map(t_data *myDatas);
int			ft_get_color(char c);

