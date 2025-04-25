/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:43:58 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/25 07:12:26 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
