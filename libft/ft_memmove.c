/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:57:36 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/21 04:00:22 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptrdest;
	char	*ptrsrc;

	if (!dest && !src)
		return (0);
	ptrdest = (char *)dest;
	ptrsrc = (char *)src ;
	if (dest > src)
		while (n--)
			ptrdest[n] = ptrsrc[n];
	else
		while (n--)
			*ptrdest++ = *ptrsrc++;
	return (dest);
}
