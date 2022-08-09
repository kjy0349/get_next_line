/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:50:22 by jeykim            #+#    #+#             */
/*   Updated: 2022/08/09 16:10:38 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_amap(int fd, char **buffer, char **buff_arr, char **ret_line)
{
	int		buff_size;
	char	*temp;

	buff_size = 1;
	while (!gnl_strchr(*buff_arr, '\n') && buff_size)
	{
		buff_size = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[buff_size] = '\0';
		temp = *buff_arr;
		*buff_arr = gnl_strjoin(*buff_arr, *buffer);
		free(temp);
		temp = NULL;
	}
	free(*buffer);
	buffer = NULL;
	get_line(ret_line, buff_arr);
	return (buff_size);
}

char	*get_line(char **ret_line, char **buff_arr)
{
	char	*temp;
	int		buff_idx;

	buff_idx = 0;
	temp = *buff_arr;
	while ((*buff_arr)[buff_idx] != '\n' && (*buff_arr)[buff_idx] != '\0')
		buff_idx++;
	if (gnl_strchr(*buff_arr, '\n'))
	{
		*ret_line = gnl_substr(*buff_arr, 0, buff_idx + 1);
		*buff_arr = gnl_strdup(*buff_arr + buff_idx + 1);
	}
	else
	{
		*ret_line = gnl_strdup(temp);
		*buff_arr = NULL;
	}
	free(temp);
	temp = NULL;
	return (*ret_line);
}

char	*get_next_line(int fd)
{
	char		*ret_line;
	static char	*buff_arr[OPEN_MAX + 1];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buff_arr[fd])
		buff_arr[fd] = gnl_strdup("");
	if (read_amap(fd, &buffer, &buff_arr[fd], &ret_line) == 0 && \
	*ret_line == '\0')
	{
		free(ret_line);
		ret_line = NULL;
		return (NULL);
	}
	return (ret_line);
}
