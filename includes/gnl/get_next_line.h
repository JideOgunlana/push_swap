/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:40:44 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/06 15:31:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TRUE 1
# define FALSE 0

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	**ft_slice(char const *s, char c);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
