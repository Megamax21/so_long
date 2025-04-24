#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_put_image(void *mlx, void *window, char *img_path, int x, int y);
char 	**ft_ber_to_array(char *map_path);
char	**ft_convert_list_to_array(t_list *list);
void	ft_error(const char *msg);
void	ft_verify_map(char **map_arr);
void	ft_verify_walls(char **map_arr);
