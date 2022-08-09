/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:58:44 by jeykim            #+#    #+#             */
/*   Updated: 2022/08/06 18:42:35 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	char	*ptr;
	char	*return_ptr;

	ptr = (char *)s;
	return_ptr = 0x00;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
		{
			return_ptr = ptr;
			break ;
		}
		ptr++;
	}
	if (c == '\0' && *ptr == '\0')
		return_ptr = ptr;
	return (return_ptr);
}

char	*gnl_strdup(const char *s1)
{
	char		*str;
	int			i;
	int			s1_len;

	s1_len = gnl_strlen(s1);
	str = (char *)malloc(sizeof(char) * s1_len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t				length;
	size_t				i;
	char				*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = gnl_strlen(s1) + gnl_strlen(s2);
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

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		n;
	size_t	slen;

	slen = gnl_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > slen)
		return (gnl_strdup(""));
	if (slen - start >= len)
		substr = (char *) malloc(len + 1);
	else
		substr = (char *) malloc(slen - start + 1);
	if (!substr)
		return (NULL);
	n = 0;
	while (start < slen && len > 0 && s[start + n] != '\0')
	{
		substr[n] = s[start + n];
		n++;
		len--;
	}
	substr[n] = '\0';
	return (substr);
}
