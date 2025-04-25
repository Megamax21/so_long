/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:32:52 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/25 06:41:53 by ml-hote          ###   ########.fr       */
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

char	**ft_dup_map(char **map)
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
	return (new_map);
}
