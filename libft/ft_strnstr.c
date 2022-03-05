/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:04:02 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/10 18:29:57 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t size)
{
	int		index;
	int		jndex;
	int		psize;

	if (*to_find == 0)
		return ((char *)src);
	jndex = -1 ;
	while (src[++jndex] && size != 0)
	{
		index = 0;
		if (src[jndex] == to_find[index])
		{
			psize = size;
			while (src[jndex + index] == to_find[index] && psize != 0)
			{
				index++;
				if (to_find[index] == '\0')
					return (&((char *)src)[jndex]);
				psize--;
			}	
		}
		size--;
	}
	return (0);
}
