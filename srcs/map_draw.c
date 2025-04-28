/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:02:00 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/28 05:28:17 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_map(t_data *myDatas)
{
	int	w;
	int	h;
	int	i;
	int	j;

	w = ft_get_map_w(myDatas->map);
	h = ft_get_map_h(myDatas->map);
	i = 0;
	j = 0;
	while (i < h)
	{
		while (j < w)
		{
			ft_put_img(myDatas, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	*ft_get_img(char c, t_data *data)
{
	if (c == '1')
		return (data->img_wall);
	if (c == '0')
		return (data->img_floor);
	if (c == 'P')
		return (data->img_player);
	if (c == 'C')
		return (data->img_collectible);
	if (c == 'E')
	{
		if (data->exit_state == 1)
			return (data->img_exit_1);
		else
			return (data->img_exit_0);
	}
	return (0);
}

void	ft_put_img(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win,
		ft_get_img(data->map[i][j], data), j * 32, i * 32);
}
