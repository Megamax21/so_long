/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/25 07:20:57 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*my_datas;
	char	*temp;
	char	*path;

	my_datas = ft_new_data(mlx_init());
	my_datas->win = mlx_new_window(my_datas->mlx, 1920, 1080, "Hello world!");
	if (ac != 2)
	{
		ft_printf("Error\nUsage : %s map.ber", av[0]);
		exit(1);
	}
	temp = ft_strjoin("./maps/", av[1]);
	path = ft_strjoin(temp, ".ber");
	free(temp);
	my_datas->map = ft_ber_to_array(path);
	free(path);
	ft_verify_map(my_datas->map);
	ft_draw_map(my_datas);
	mlx_loop(my_datas->mlx);
	return (0);
}
/*
void	ft_put_image(void *mlx, void *window, char *img_path, int x, int y)
{
	void	*img;
	int		h;
	int		w;

	img = mlx_xpm_file_to_image(mlx, img_path, &w, &h);
	mlx_put_image_to_window(mlx, window, img, x, y);
}
*/
