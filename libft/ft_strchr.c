/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:40:09 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/10 15:32:23 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int nbr)
{
	while (*str != (char)nbr)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
