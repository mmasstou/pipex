/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:38:06 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/14 19:13:03 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n <= 0)
	{
		n = -n;
		size++;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_signe(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				nbrlen;
	unsigned int	nbr;

	nbr = n;
	nbrlen = ft_nbrlen(n);
	if (nbrlen == 0)
		nbrlen = 1;
	str = (char *)malloc((nbrlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[nbrlen] = '\0';
	if (ft_signe(nbr))
		nbr = -nbr;
	while (nbr)
	{
		str[--nbrlen] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n == 0)
		str[0] = n % 10 + 48;
	if (ft_signe(n))
		str[0] = '-';
	return (str);
}
