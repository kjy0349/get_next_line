/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:58:44 by jeykim            #+#    #+#             */
/*   Updated: 2022/05/24 19:49:21 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const void	*s;
	void		*d;
	size_t		i;

	s = src;
	d = dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			((unsigned char *)d)[len] = ((unsigned char *)s)[len];
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)d)[i] = ((unsigned char *)s)[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t				length;
	char				*str;
	size_t				i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * length + 1);
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

void	add_buff_last(t_blist **buff_list, char *buffer, int fd)
{
	t_blist	*new_buff;

	new_buff = (t_blist *)malloc(sizeof(t_blist));
	if (!new_buff)
		return (NULL);
	new_buff->fd = fd;
	new_buff->buffer = buffer;
	new_buff->next = NULL;
	while (*buff_list)
		*buff_list = (*buff_list)->next;
	*buff_list = new_buff;
}
