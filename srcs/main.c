/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/28 05:59:08 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*my_datas;
	char	*temp;
	char	*path;

	if (ac != 2)
	{
		ft_printf("Error\nUsage : %s map", av[0]);
		exit(1);
	}
	my_datas = ft_new_data(mlx_init());
	temp = ft_strjoin("./maps/", av[1]);
	path = ft_strjoin(temp, ".ber");
	free(temp);
	my_datas->map = ft_ber_to_array(path);
	free(path);
	ft_verify_map(&my_datas);
	my_datas->win = mlx_new_window(my_datas->mlx,
			ft_get_map_w(my_datas->map) * 32,
			ft_get_map_h(my_datas->map) * 32, "Hello world!");
	ft_draw_map(my_datas);
	mlx_hook(my_datas->win, 2, 1L << 0, ft_key_press, my_datas);
	mlx_hook(my_datas->win, 17, 0L, (int (*)())ft_close_window, my_datas);
	mlx_loop(my_datas->mlx);
	return (0);
}

int	ft_close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_close_window(data);
	else if (keycode == 119)
		ft_move_up(&data);
	else if (keycode == 115)
		ft_move_down(&data);
	else if (keycode == 97)
		ft_move_left(&data);
	else if (keycode == 100)
		ft_move_right(&data);
	if (data->collectibles == 0 && data->p_x == data->e_x
		&& data->p_y == data->e_y)
		ft_close_window(data);
	return (0);
}
