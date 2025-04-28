/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 06:33:13 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/28 05:27:28 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(const char *msg)
{
	if (msg)
	{
		write(2, "Error\n", 6);
		perror(msg);
	}
	else
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	**ft_convert_list_to_array(t_list *list)
{
	char	**array;
	int		i;
	int		width;
	t_list	*tmp;

	i = 0;
	width = -1;
	array = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!array)
		ft_error("Malloc didn't malloc");
	tmp = list;
	while (tmp)
	{
		if (width == -1)
			width = ft_strlen(tmp->content);
		else if (ft_strlen(tmp->content) != (size_t)width)
			ft_error("Map isn't a rectangle");
		array[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}

t_data	*ft_new_data(void *mlx)
{
	t_data	*new;
	int		w;
	int		h;

	new = (t_data *)malloc(sizeof(t_data));
	new->mlx = mlx;
	new->win = NULL;
	new->map = NULL;
	new->exit_state = 0;
	new->img_collectible = mlx_xpm_file_to_image(new->mlx,
			"./imgs/collectible.xpm", &w, &h);
	new->img_floor = mlx_xpm_file_to_image(new->mlx,
			"./imgs/floor.xpm", &w, &h);
	new->img_exit_0 = mlx_xpm_file_to_image(new->mlx,
			"./imgs/exit_0.xpm", &w, &h);
	new->img_exit_1 = mlx_xpm_file_to_image(new->mlx,
			"./imgs/exit_1.xpm", &w, &h);
	new->img_player = mlx_xpm_file_to_image(new->mlx,
			"./imgs/player_0.xpm", &w, &h);
	new->img_wall = mlx_xpm_file_to_image(new->mlx,
			"./imgs/wall.xpm", &w, &h);
	return (new);
}
