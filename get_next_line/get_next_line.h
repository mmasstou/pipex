/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:36:58 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/30 12:34:37 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*read_file(char *buffer_static, int fd);
char	*get_line(char *buffer_static);
char	*update_buffer(char *buffer_static);
size_t	ft_strlen(const char *str);
int		cheak_buffer(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif
