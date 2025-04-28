/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:35:15 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/28 03:51:48 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_strange_char(char **map_arr, int w, int h)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (map_arr[y][x] != 'P' && map_arr[y][x] != '1'
				&& map_arr[y][x] != 'C' && map_arr[y][x] != '0'
				&& map_arr[y][x] != 'E')
			{
				ft_printf("Error\nNo tile for char : %c\n", map_arr[y][x]);
				exit(1);
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	ft_check_player_on_map(char **map_arr, int w, int h)
{
	int	x;
	int	y;
	int	p;

	p = 0;
	x = 1;
	y = 1;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (map_arr[y][x] == 'P')
				p++;
			x++;
		}
		x = 1;
		y++;
	}
	if (p == 0 || p > 1)
	{
		ft_printf("Error\nNo player or more than one were found in map !\n");
		exit(1);
	}
}

int	ft_check_exit_on_map(char **map_arr, int is_flood)
{
	int	e;

	e = ft_count_tile(map_arr, 'E');
	if ((e == 0 || e > 1) && is_flood == 0)
	{
		ft_printf("Error\nNo exit or more than one were found in map !\n");
		exit(1);
	}
	return (e);
}

int	ft_check_collectibles_on_map(char **map_arr, int is_flood)
{
	int	c;

	c = ft_count_tile(map_arr, 'C');
	if (c == 0 && is_flood == 0)
	{
		ft_printf("Error\nNo collectible were found in map !\n");
		exit(1);
	}
	return (c);
}

void	ft_check_map_after_flood(char **map)
{
	char	**map_tmp;
	int		p_x;
	int		p_y;

	p_x = 0;
	p_y = 0;
	map_tmp = ft_dup_map(map);
	while (map[p_y])
	{
		while (map[p_y][p_x])
		{
			if (map[p_y][p_x] == 'P')
				ft_flood_fill(map_tmp, p_x, p_y);
			p_x++;
		}
		p_x = 0;
		p_y++;
	}
	if (ft_check_collectibles_on_map(map_tmp, 1) > 0
		&& ft_check_collectibles_on_map(map_tmp, 1) > 0)
	{
		ft_printf("Error\nExit or collectible isn't accessible by player\n");
		exit(1);
	}
}
