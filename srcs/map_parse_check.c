/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:35:15 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/25 06:39:50 by ml-hote          ###   ########.fr       */
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

int	ft_check_exit_on_map(char **map_arr, int w, int h, int is_flood)
{
	int	x;
	int	y;
	int	e;

	e = 0;
	x = 1;
	y = 1;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (map_arr[y][x] == 'E')
				e++;
			x++;
		}
		x = 1;
		y++;
	}
	if ((e == 0 || e > 1) && is_flood == 0)
	{
		ft_printf("Error\nNo exit or more than one were found in map !\n");
		exit(1);
	}
	return (e);
}

int	ft_check_collectibles_on_map(char **map_arr, int w, int h, int is_flood)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	x = 1;
	y = 1;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (map_arr[y][x] == 'C')
				c++;
			x++;
		}
		x = 1;
		y++;
	}
	if (c == 0 && is_flood == 0)
	{
		ft_printf("Error\nNo collectible were found in map !\n");
		exit(1);
	}
	return (c);
}

void	ft_check_map_after_flood(char **map, int w, int h)
{
	char	**map_tmp;
	int		player_x;
	int		player_y;

	player_x = 0;
	player_y = 0;
	map_tmp = ft_dup_map(map);
	while (map[player_y])
	{
		while (map[player_y][player_x])
		{
			if (map[player_y][player_x] == 'P')
				ft_flood_fill(map_tmp, player_x, player_y);
			player_x++;
		}
		player_x = 0;
		player_y++;
	}
	if (ft_check_collectibles_on_map(map_tmp, w, h, 1) > 0
		&& ft_check_collectibles_on_map(map_tmp, w, h, 1) > 0)
	{
		ft_printf("Error\nExit or collectible isn't accessible by player\n");
		exit(1);
	}
}
