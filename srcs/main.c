/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/30 20:57:59 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*my_datas;

	my_datas = NULL;
	if (ac != 2)
	{
		ft_printf("Error\nUsage : %s map", av[0]);
		exit(1);
	}
	my_datas = ft_new_data(mlx_init());
	my_datas->map = ft_dup_map(ft_ber_to_array(av[1], my_datas), 1);
	ft_verify_map(&my_datas);
	my_datas->win = mlx_new_window(my_datas->mlx,
			ft_get_map_w(my_datas->map) * 32,
			ft_get_map_h(my_datas->map) * 32, "Hello world!");
	ft_draw_map(my_datas);
	mlx_hook(my_datas->win, 2, 1L << 0, ft_key_press, my_datas);
	mlx_hook(my_datas->win, 17, 0L, ft_close_win_free_map, my_datas);
	mlx_loop(my_datas->mlx);
	return (0);
}

int	ft_close_window(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img_collectible);
	mlx_destroy_image(data->mlx, data->img_exit_0);
	mlx_destroy_image(data->mlx, data->img_exit_1);
	mlx_destroy_image(data->mlx, data->img_floor);
	mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}

int	ft_key_press(int keycode, t_data *data)
{
	int	move_init;

	move_init = data->p_moves;
	if (keycode == 65307)
	{
		ft_free_char_array(data->map);
		ft_close_window(data);
	}
	else if (keycode == 119)
		data->p_moves += ft_move_up(&data);
	else if (keycode == 115)
		data->p_moves += ft_move_down(&data);
	else if (keycode == 97)
		data->p_moves += ft_move_left(&data);
	else if (keycode == 100)
		data->p_moves += ft_move_right(&data);
	if (data->collectibles == 0 && data->p_x == data->e_x
		&& data->p_y == data->e_y)
	{
		ft_free_char_array(data->map);
		ft_close_window(data);
	}
	if (move_init != data->p_moves)
		ft_printf("Moves : %i\n", data->p_moves);
	return (0);
}

void	ft_free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

int	ft_close_win_free_map(t_data *data)
{
	ft_free_char_array(data->map);
	ft_close_window(data);
	return (0);
}
