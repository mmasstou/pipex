/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 04:11:08 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/06 04:11:15 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = -1;
	while (str[++index])
		;
	return (index);
}

int	cheak_buffer(char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		else
			str++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (elementCount * elementSize))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
