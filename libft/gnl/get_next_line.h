/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:35:20 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/24 05:54:36 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // used by read(), STDOUT_FILENO, STDERR_FILENO
# include <stdlib.h> // definition of size_t and NULL (e.g.: ft_memset)
# include <errno.h> // definition of error codes (e.g.: ft_calloc)
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GNL_END_OF_FILE 0
# define GNL_NEWLINE 1

char	*ft_previous(const char *s);
char	*ft_next(char *s);
int		ft_newline(const char *s);
char	*ft_read(int fd, char *buffer, char *tmp, char *s);
char	*get_next_line(int fd);

void	safe_free(char *s);

#endif
