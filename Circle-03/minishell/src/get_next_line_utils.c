/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:54:57 by dason             #+#    #+#             */
/*   Updated: 2021/11/03 14:10:11 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*store_buff;
	size_t	index;
	size_t	s_index;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	store_buff = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!store_buff)
		return (NULL);
	index = 0;
	s_index = 0;
	while (s_index < s1_len)
		store_buff[index++] = s1[s_index++];
	s_index = 0;
	while (s_index < s2_len)
		store_buff[index++] = s2[s_index++];
	free(s1);
	s1 = NULL;
	return (store_buff);
}

size_t	ft_isnewline(char *s)
{
	size_t	 index;

	if (!s)
		return (0);
	index = 0;
	while (s[index])
	{
		if (s[index] == '\n')
			return (index + 1);
		index++;
	}
	return (0);
}

char	*gnl_strdup(char *s)
{
	char	*line;
	size_t	len;
	size_t	index;

	len = gnl_strlen(s);
	index = 0;
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (index < len)
	{
		line[index] = s[index];
		index++;
	}
	return (line);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*tmp_ptr;
	size_t	n;

	n = count * size;
	ptr = malloc(sizeof(char) * n);
	if (!ptr)
		return (NULL);
	tmp_ptr = ptr;
	while (n--)
		*tmp_ptr++ = 0;
	return (ptr);
}
