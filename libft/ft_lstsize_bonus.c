/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:26:40 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/28 03:54:37 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		n++;
		lst = lst -> next;
	}
	return (n);
}
