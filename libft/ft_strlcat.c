/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:54:08 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/24 20:58:34 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	index;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size == 0 || size <= d_len)
		return (s_len + size);
	index = 0;
	while (index < s_len && index < size - d_len - 1)
	{
		dest[d_len + index] = src[index];
		index++;
	}
	dest[d_len + index] = '\0';
	return (d_len + s_len);
}
