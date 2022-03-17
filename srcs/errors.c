/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:28:00 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/17 16:28:46 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	pipex_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}
