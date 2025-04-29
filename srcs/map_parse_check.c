/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:35:15 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/29 18:32:30 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_strange_char(t_data *data, int w, int h)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < (h - 1))
	{
		while (x < (w - 1))
		{
			if (data->map[y][x] != 'P' && data->map[y][x] != '1'
				&& data->map[y][x] != 'C' && data->map[y][x] != '0'
				&& data->map[y][x] != 'E')
			{
				ft_printf("Error\nNo tile for char : %c\n", data->map[y][x]);
				ft_free_char_array(data->map);
				ft_close_window(data);
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	ft_check_player_on_map(t_data *data, int w, int h)
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
			if (data->map[y][x] == 'P')
				p++;
			x++;
		}
		x = 1;
		y++;
	}
	if (p == 0 || p > 1)
	{
		ft_printf("Error\nNo player or more than one were found in map !\n");
		ft_free_char_array(data->map);
		ft_close_window(data);
	}
}

int	ft_check_exit_on_map(t_data *data)
{
	int	e;

	e = ft_count_tile(data->map, 'E');
	if ((e == 0 || e > 1))
	{
		ft_printf("Error\nNo exit or more than one were found in map !\n");
		ft_free_char_array(data->map);
		ft_close_window(data);
	}
	return (e);
}

int	ft_check_collectibles_on_map(t_data *data)
{
	int	c;

	c = ft_count_tile(data->map, 'C');
	if (c == 0)
	{
		ft_printf("Error\nNo collectible were found in map !\n");
		ft_free_char_array(data->map);
		ft_close_window(data);
	}
	return (c);
}

void	ft_check_map_after_flood(t_data *data)
{
	char	**map_tmp;

	map_tmp = ft_dup_map(data->map, 0);
	ft_flood_fill(map_tmp, data->p_x, data->p_y);
	if (ft_count_tile(map_tmp, 'C') > 0
		|| ft_count_tile(map_tmp, 'E') > 0)
	{
		ft_printf("Error\nExit or collectible isn't accessible by player\n");
		ft_free_char_array(map_tmp);
		ft_close_window(data);
	}
	ft_free_char_array(map_tmp);
}
