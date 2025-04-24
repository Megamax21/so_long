/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/24 03:52:40 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	// t_data	img;

	printf("INIT !\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	if (ac != 2)
		return (-1);
	
	ft_put_image(mlx, mlx_win, "./imgs/spr_john_0.xpm", 300, 150);
	ft_ber_to_array(ft_strjoin(ft_strjoin("./maps/", av[1]), ".ber"));
	mlx_loop(mlx);

	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_put_image(void *mlx, void *window, char *img_path, int x, int y)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx, img_path, &w, &h);
	mlx_put_image_to_window(mlx, window, img, x, y);
}