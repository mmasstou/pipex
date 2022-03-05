/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:47:13 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/09 16:32:24 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	char	*str;

	string = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!string)
		return (NULL);
	str = string;
	while (*s)
		*string++ = *s++;
	*string = 0;
	return (str);
}
