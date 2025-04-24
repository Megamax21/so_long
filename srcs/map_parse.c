/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 02:49:58 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/24 06:59:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_ber_to_array(char *map_path)
{
	int		map_fd;
	t_list	*lines;
	char	*line;
	char	**map_array;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		ft_error(map_path);
	lines = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		ft_lstadd_back(&lines, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	map_array = ft_convert_list_to_array(lines);
	ft_lstclear(&lines, free);
	return (map_array);
}

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
		array[i++] = tmp->content;
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}

/* Map verification will be done in multiple parts
	1. Check if it is surrounded by walls
		+ Check if there's not more blocks around
	2. Check if there's only one player
	3. Check if there's at least 1 collectible
	4. Check if there's only one exit
	5. Floodfill of the map to be sure that the 
		player can acess both the collectibles 
		& the exit
*/
void ft_verify_map(char **map_arr)
{
	
}
