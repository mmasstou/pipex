/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:58:00 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/19 10:53:42 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int s)
{
	char	*space;

	space = "\f\n\r\t\v ";
	while (*space)
		if (s == *space++)
			return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -signe;
		str++ ;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str - 48;
		str++;
	}
	result *= signe;
	return (result);
}
