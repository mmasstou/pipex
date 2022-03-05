/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:13:42 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/23 19:23:49 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (!s)
		return ;
	index = 0 ;
	if (f)
	{
		while (s[index])
		{
			(*f)(index, s + index);
			index++;
		}
	}
}
