/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:57:03 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/21 02:37:09 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copy_substring;
	char			*substring;
	char			*str;
	unsigned int	index;
	size_t			srclen;

	if (!s)
		return (NULL);
	str = (char *)s;
	srclen = ft_strlen(s);
	index = len;
	if (start >= srclen)
		return (ft_strdup(""));
	if (index > srclen)
		index = srclen;
	substring = (char *)malloc(index + 1);
	copy_substring = substring;
	if (!substring)
		return (NULL);
	str += start;
	while (*str && len-- > 0)
		*substring++ = *str++;
	*substring = 0;
	return (copy_substring);
}
