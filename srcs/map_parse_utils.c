/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:32:52 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/29 18:40:28 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_get_map_h(char **map)
{
	int	h;

	h = 0;
	while (map[h] != NULL)
		h++;
	return (h);
}

int	ft_get_map_w(char **map)
{
	return (ft_strlen(map[0]));
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

char	**ft_dup_map(char **map, int free_map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	if (free_map == 1)
		ft_free_char_array(map);
	return (new_map);
}

int	ft_count_tile(char **map, char tile)
{
	int	i;
	int	w;
	int	h;
	int	x;
	int	y;

	x = 0;
	y = 0;
	w = ft_get_map_w(map);
	h = ft_get_map_h(map);
	i = 0;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (map[y][x] == tile)
				i++;
			x++;
		}
		x = 1;
		y++;
	}
	return (i);
}
