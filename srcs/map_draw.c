/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:02:00 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/25 09:17:48 by ml-hote          ###   ########.fr       */
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
			ft_put_square(myDatas, j * 32, i * 32,
				ft_get_color(myDatas->map[i][j]));
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_get_color(char c)
{
	if (c == '1')
		return (0x00F0E0B6);
	if (c == '0')
		return (0x00000000);
	if (c == 'P')
		return (0x005583C9);
	if (c == 'C')
		return (0x00FCE300);
	if (c == 'E')
		return (0x008C0017);
	return (0);
}
