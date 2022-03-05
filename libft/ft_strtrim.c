/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:56:33 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/15 10:06:14 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_instring(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		index;
	int		jndex;
	int		zndex;

	if (!s1)
		return (NULL);
	jndex = ft_strlen(s1);
	while (s1[--jndex] && is_instring(s1[jndex], set))
		;
	index = -1;
	while (s1[++index] && is_instring(s1[index], set))
		;
	if (jndex == -1)
		jndex = index;
	zndex = jndex - index;
	strtrim = (char *)malloc(zndex + 2);
	if (!strtrim)
		return (NULL);
	zndex = index;
	while (s1[index] && index <= jndex)
		*strtrim++ = s1[index++];
	*strtrim = 0;
	return (strtrim - (index - zndex));
}
