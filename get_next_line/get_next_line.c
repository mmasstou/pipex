/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 04:10:02 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/06 04:10:06 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buffer(char *buffer_static)
{
	char	*str;
	int		index;
	int		jndex;
	int		len;

	index = 0;
	while (buffer_static[index] && buffer_static[index] != '\n')
		index++;
	if (!buffer_static[index])
	{
		free(buffer_static);
		return (NULL);
	}
	len = ft_strlen(buffer_static) - index + 1;
	str = (char *)ft_calloc(len, 1);
	if (!str)
		return (NULL);
	index++;
	jndex = 0;
	while (buffer_static[index])
		str[jndex++] = buffer_static[index++];
	free(buffer_static);
	return (str);
}

static char	*ft_get_strjoin(char *buffer_static, char *buffer)
{
	char	*str;

	str = ft_strjoin(buffer_static, buffer);
	free(buffer_static);
	return (str);
}

char	*get_line(char *buffer_static)
{
	char	*ret_str;
	int		index;

	index = 0;
	if (!buffer_static[index])
		return (NULL);
	while (buffer_static[index] && buffer_static[index] != '\n')
		index++;
	index++;
	ret_str = (char *)ft_calloc(index + 1, 1);
	if (!ret_str)
		return (NULL);
	index = 0;
	while (buffer_static[index] && buffer_static[index] != '\n')
	{
		ret_str[index] = buffer_static[index];
		index++;
	}
	if (buffer_static[index] && buffer_static[index] == '\n')
		ret_str[index++] = '\n';
	return (ret_str);
}

char	*read_file(char *buffer_static, int fd)
{
	char	*buffer;
	int		index_read;

	if (!buffer_static)
		buffer_static = (char *)ft_calloc(1, 1);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (cheak_buffer(buffer_static) == 0)
	{
		index_read = read(fd, buffer, BUFFER_SIZE);
		if (index_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[index_read] = 0;
		if (index_read == 0)
			break ;
		else
			buffer_static = ft_get_strjoin(buffer_static, buffer);
	}
	free(buffer);
	return (buffer_static);
}

char	*get_next_line(int fd)
{
	static char	*buffer_static;
	char		*ret_string;

	ret_string = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer_static = read_file(buffer_static, fd);
	ret_string = get_line(buffer_static);
	buffer_static = update_buffer(buffer_static);
	return (ret_string);
}
