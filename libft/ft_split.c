/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:22:31 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/23 19:03:05 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_tab_element(char const	*string, char delimiter)
{
	int	delimiternbr;

	delimiternbr = 0;
	while (*string && *string == delimiter)
		string++;
	if (*string)
		delimiternbr = 1;
	else
		delimiternbr = 0;
	while (*string)
	{
		if (*string == delimiter && string[1] && string[1] != delimiter)
			delimiternbr++;
		string++;
	}
	return (delimiternbr);
}

static void	free_array(char **tab, int nbrele)
{
	int	index;

	index = -1;
	while (++index <= nbrele)
		free(tab[index]);
}

static void	creat_tab(char **array, char const *s, char delimiter, int nbrele)
{
	int		index[2];
	char	*str;

	index[1] = 0;
	str = (char *)s;
	while (*s != '\0')
	{
		while (*s && *s == delimiter)
		{
			index[1]++;
			s++;
		}
		index[0] = 0;
		while (*s != '\0' && *s != delimiter)
		{
			index[0]++;
			s++;
		}
		if (nbrele--)
			*(array++) = ft_substr(str, index[1], index[0]);
		str += index[0];
	}
}

char	**ft_split(char const *s, char delimiter)
{
	char	**array;
	int		nbrele;
	int		index;

	if (!s)
		return (0);
	nbrele = count_tab_element(s, delimiter);
	array = (char **)malloc(sizeof(char *) * (nbrele + 1));
	if (!array)
		return (0);
	array[nbrele] = NULL;
	creat_tab(array, s, delimiter, nbrele);
	index = -1;
	while (array[++index] && nbrele-- > 0)
	{
		if (!array[index])
		{
			free_array(array, nbrele);
			return (NULL);
		}
	}
	return (array);
}
