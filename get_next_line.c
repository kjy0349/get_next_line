/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:50:22 by jeykim            #+#    #+#             */
/*   Updated: 2022/05/24 19:25:36 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_blist	*buff_list;
	char			*line;
	char			*ret_line;
	int				return_num;
	int				size;

	buff_list = (t_blist *)malloc(sizeof(t_blist));
	line = get_buffer(&buff_list, fd)->buffer;
	return_num = read(fd, line, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || return_num == -1)
		return (NULL);
	size = 0;
	while (line[size] != "\n" && size < return_num)
		size++;
	ret_line = (char *)malloc(sizeof(char) * size);
	ft_memmove(ret_line, line, size);
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
