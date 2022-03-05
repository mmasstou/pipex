/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:16:57 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/10 16:01:30 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char )c;
	while (n--)
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
	}
	return (0);
}
