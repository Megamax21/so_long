/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 01:19:42 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/28 05:21:28 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_up(t_data **data)
{
	char	tile;
	int		x;
	int		y;

	x = (*data)->p_x;
	y = (*data)->p_y;
	tile = (*data)->map[y - 1][x];
	if (tile == '1')
		return (0);
	(*data)->p_y--;
	if ((*data)->map[y - 1][x] == 'C')
		(*data)->collectibles--;
	(*data)->map[y - 1][x] = 'P';
	if ((*data)->e_x == x && (*data)->e_y == y)
		(*data)->map[y][x] = 'E';
	else
		(*data)->map[y][x] = '0';
	if ((*data)->collectibles == 0)
	{
		(*data)->exit_state = 1;
		ft_put_img((*data), (*data)->e_y, (*data)->e_x);
	}
	ft_put_img((*data), y - 1, x);
	ft_put_img((*data), y, x);
	return (1);
}

int	ft_move_left(t_data **data)
{
	char	tile;
	int		x;
	int		y;

	x = (*data)->p_x;
	y = (*data)->p_y;
	tile = (*data)->map[y][x - 1];
	if (tile == '1')
		return (0);
	(*data)->p_x--;
	if ((*data)->map[y][x - 1] == 'C')
		(*data)->collectibles--;
	(*data)->map[y][x - 1] = 'P';
	if ((*data)->e_x == x && (*data)->e_y == y)
		(*data)->map[y][x] = 'E';
	else
		(*data)->map[y][x] = '0';
	if ((*data)->collectibles == 0)
	{
		(*data)->exit_state = 1;
		ft_put_img((*data), (*data)->e_y, (*data)->e_x);
	}
	ft_put_img((*data), y, x - 1);
	ft_put_img((*data), y, x);
	return (1);
}

int	ft_move_down(t_data **data)
{
	char	tile;
	int		x;
	int		y;

	x = (*data)->p_x;
	y = (*data)->p_y;
	tile = (*data)->map[y + 1][x];
	if (tile == '1')
		return (0);
	(*data)->p_y++;
	if ((*data)->map[y + 1][x] == 'C')
		(*data)->collectibles--;
	(*data)->map[y + 1][x] = 'P';
	if ((*data)->e_x == x && (*data)->e_y == y)
		(*data)->map[y][x] = 'E';
	else
		(*data)->map[y][x] = '0';
	if ((*data)->collectibles == 0)
	{
		(*data)->exit_state = 1;
		ft_put_img((*data), (*data)->e_y, (*data)->e_x);
	}
	ft_put_img((*data), y + 1, x);
	ft_put_img((*data), y, x);
	return (1);
}

int	ft_move_right(t_data **data)
{
	char	tile;
	int		x;
	int		y;

	x = (*data)->p_x;
	y = (*data)->p_y;
	tile = (*data)->map[y][x + 1];
	if (tile == '1')
		return (0);
	(*data)->p_x++;
	if ((*data)->map[y][x + 1] == 'C')
		(*data)->collectibles--;
	(*data)->map[y][x + 1] = 'P';
	if ((*data)->e_x == x && (*data)->e_y == y)
		(*data)->map[y][x] = 'E';
	else
		(*data)->map[y][x] = '0';
	if ((*data)->collectibles == 0)
	{
		(*data)->exit_state = 1;
		ft_put_img((*data), (*data)->e_y, (*data)->e_x);
	}
	ft_put_img((*data), y, x + 1);
	ft_put_img((*data), y, x);
	return (1);
}
