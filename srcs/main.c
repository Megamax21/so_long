/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/24 00:20:46 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	// t_data	img;

	printf("INIT !\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	printf("1 !\n");
	// int	i = 200;
	// while (i < 500)
	// {
	// 	my_mlx_pixel_put(&img, i, 50, 0x00FF0000);
	// 	i++;
	// }
	printf("2 !\n");
	ft_put_image(mlx, mlx_win, "./imgs/spr_john_0.xpm", 300, 150);
	printf("3 !\n");
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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

	printf("TEST 1 !\n");
	img = mlx_xpm_file_to_image(mlx, img_path, &w, &h);
	printf("w : %i\th : %i\n", w, h);
	mlx_put_image_to_window(mlx, window, img, x, y);
}