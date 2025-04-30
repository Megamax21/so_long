/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 02:49:58 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/30 20:57:37 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_ber_to_array(char *map_path, t_data *data)
{
	int		map_fd;
	t_list	*lines;
	char	*line;
	char	**return_arr;

	if (ft_check_if_ber(map_path) == 0)
	{
		ft_printf("Error\nFile is not a .ber file\n");
		ft_close_window(data);
	}
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		ft_error(map_path);
	lines = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		ft_lstadd_back(&lines, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	return_arr = ft_convert_list_to_array(lines, data);
	return (return_arr);
}

/* Map verification will be done in multiple parts
	* 1. Check if it is surrounded by walls
		+ Check if there's not more blocks around
	* 2. Check if there's only one player
	* 3. Check if there's at least 1 collectible
	* 4. Check if there's only one exit
	5. Floodfill of the map to be sure that the 
		player can acess both the collectibles 
		& the exit
*/
void	ft_verify_map(t_data **data)
{
	int		width;
	int		height;
	char	**map_tmp;

	width = ft_get_map_w((*data)->map);
	height = ft_get_map_h((*data)->map);
	ft_check_strange_char((*data), width, height);
	ft_verify_walls((*data), width, height);
	ft_check_player_on_map(*data, width, height);
	ft_assign_player_pos(data, width, height);
	ft_check_exit_on_map((*data));
	ft_check_collectibles_on_map((*data));
	map_tmp = ft_dup_map((*data)->map, 0);
	ft_check_map_after_flood((*data), map_tmp);
	ft_assign_exit_pos(*data);
	(*data)->collectibles = ft_count_tile((*data)->map, 'C');
}

void	ft_verify_walls(t_data *data, int w, int h)
{
	int	i;

	i = 0;
	while (i < w)
	{
		if (data->map[0][i] != '1' || data->map[h - 1][i] != '1')
		{
			ft_printf("Error\nMap isn't surrounded by walls !\n");
			ft_free_char_array(data->map);
			ft_close_window(data);
		}
		i++;
	}
	i = 0;
	while (i < h)
	{
		if (data->map[i][0] != '1' || data->map[i][w - 1] != '1')
		{
			ft_printf("Error\nMap isn't surrounded by walls !\n");
			ft_free_char_array(data->map);
			ft_close_window(data);
		}
		i++;
	}
}

void	ft_assign_player_pos(t_data **data, int w, int h)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (((*data)->map)[y][x] == 'P')
			{
				(*data)->p_x = x;
				(*data)->p_y = y;
				return ;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	ft_assign_exit_pos(t_data *data)
{
	int	w;
	int	h;
	int	x;
	int	y;

	x = 1;
	y = 1;
	w = ft_get_map_w(data->map);
	h = ft_get_map_h(data->map);
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if ((data->map)[y][x] == 'E')
			{
				data->e_x = x;
				data->e_y = y;
				return ;
			}
			x++;
		}
		x = 1;
		y++;
	}
}
