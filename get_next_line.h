/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:50:53 by jeykim            #+#    #+#             */
/*   Updated: 2022/07/20 18:47:32 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "stdbool.h"

typedef struct buffer_list
{
	int					fd;
	char				*buffer;
	struct buffer_list	*next;
}	t_blist;

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	join_and_setbuffer(t_blist **buff_list, char *buffer, int fd);
void	add_buff_last(t_blist **buff_list, char *buffer, int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
