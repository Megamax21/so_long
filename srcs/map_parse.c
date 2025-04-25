/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 02:49:58 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/25 07:25:03 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_ber_to_array(char *map_path)
{
	int		map_fd;
	t_list	*lines;
	char	*line;

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
	return (ft_convert_list_to_array(lines));
	ft_lstclear(&lines, free);
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
void	ft_verify_map(char **map_arr)
{
	int		width;
	int		height;

	width = ft_get_map_w(map_arr);
	height = ft_get_map_h(map_arr);
	ft_printf("My map has a width of %i and a height of %i\n", width, height);
	ft_check_strange_char(map_arr, width, height);
	ft_verify_walls(map_arr, width, height);
	ft_check_player_on_map(map_arr, width, height);
	ft_check_exit_on_map(map_arr, width, height, 0);
	ft_check_collectibles_on_map(map_arr, width, height, 0);
	ft_check_map_after_flood(map_arr, width, height);
}

void	ft_verify_walls(char **map_arr, int w, int h)
{
	int	i;

	i = 0;
	while (i < w)
	{
		if (map_arr[0][i] != '1' || map_arr[h - 1][i] != '1')
		{
			ft_printf("Error\nMap isn't surrounded by walls !\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < h)
	{
		if (map_arr[i][0] != '1' || map_arr[i][w - 1] != '1')
		{
			ft_printf("Error\nMap isn't surrounded by walls !\n");
			exit(1);
		}
		i++;
	}
}
