/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:50:22 by jeykim            #+#    #+#             */
/*   Updated: 2022/07/20 18:51:21 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_blist	**find_and_join(t_blist **buff_list, char *buffer, int fd)
{
	int	buf_size;

	buf_size = ft_strlen(buffer);
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
		(*buff_list)->buffer = (char *)malloc(sizeof(char) * buf_size);
		ft_memmove((*buff_list)->buffer, buffer, buf_size);
		(*buff_list)->next = NULL;
	}
	return (buff_list);
}

char	*getline_and_setbuffer(t_blist	**buff_list)
{
	int		size;
	int		i;
	char	*line;
	char	*buffer;
	int		buf_size;

	size = 0;
	buffer = (*buff_list)->buffer;
	buf_size = ft_strlen(buffer);
	while (buffer[size] != '\n' && buffer[size] != -1 && buffer[size] != '\0')
		size++;
	line = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	ft_memmove(buffer, buffer + size, size);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_blist	**buff_list;
	char			*buffer;
	char			*ret_line;
	int				return_num;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	return_num = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || return_num == -1 || !buffer)
		return (NULL);
	if (!buff_list)
	{
		buff_list = (char **)malloc(sizeof(char *));
		(*buff_list)->next = NULL;
		(*buff_list)->fd = 0;
		(*buff_list)->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	}
	ret_line = getline_and_setbuffer(find_and_join(buff_list, buffer, fd));
	return (ret_line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (line = get_next_line(fd))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
}
