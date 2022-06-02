/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:50:22 by jeykim            #+#    #+#             */
/*   Updated: 2022/06/02 14:43:40 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_getline(t_blist **buff_list, char *buffer, int fd)
{
	while (*buff_list)
	{
		if ((*buff_list)->fd == fd)
			break ;
		*buff_list = (*buff_list)->next;
	}
	if (*buff_list)
		ft_strjoin((*buff_list)->buffer, buffer);
	else
	{
		*buff_list = (t_blist *)malloc(sizeof(t_blist));
		(*buff_list)->fd = fd;
		(*buff_list)->buffer = buffer;
		(*buff_list)->next = NULL;
	}
	return ((*buff_list)->buffer);
}

char	*get_line(char	*buffer)
{
	int		size;
	int		i;
	char	*line;

	size = 0;
	while (buffer[size] != '\n' || buffer[size] != -1)
		size++;
	line = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_blist	*buff_list;
	char			*buffer;
	char			*ret_line;
	int				return_num;

	return_num = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || return_num == -1)
		return (NULL);
	ret_line = get_line(join_and_getline(&buff_list, buffer, fd));
	return (ret_line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (!(line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
}
