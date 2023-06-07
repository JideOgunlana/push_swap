/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:40:01 by bogunlan          #+#    #+#             */
/*   Updated: 2023/06/07 06:09:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[i] != '\0') && (j != len))
	{
		while (i == start && j < len)
		{
			substr[j] = s[j + i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

/* char	**ft_free(int res_st_i, char **res)
{
	while (0 <= res_st_i)
	{
		free(res[res_st_i]);
		res_st_i--;
	}
	free(res);
	return (NULL);
} */

char	**ft_gen(const char *s, char c, char **res, int res_s_i)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen_gnl(s))
	{
		if (s[i] == c)
		{
			res[res_s_i] = ft_substr_gnl(s, 0, i + 1);
			if (res[res_s_i] == NULL)
				return (ft_free(res));
			res_s_i++;
			break ;
		}
		i++;
	}
	if (ft_strchr(s, '\n'))
		res[res_s_i] = ft_substr_gnl(s, i + 1, ft_strlen_gnl(s) - (i + 1));
	else
		res[res_s_i++] = ft_substr_gnl(s, 0, ft_strlen_gnl(s));
	res[++res_s_i] = NULL;
	return (res);
}

char	**ft_slice(char const *s, char c)
{
	char	**sarray;
	int		sarray_start_index;

	sarray_start_index = 0;
	if (!s)
		return (NULL);
	sarray = (char **) malloc(sizeof(char *) * 3);
	if (!sarray)
		return (NULL);
	sarray = ft_gen(s, c, sarray, sarray_start_index);
	return (sarray);
}
