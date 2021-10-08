/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sondho <sondho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:43:32 by dason             #+#    #+#             */
/*   Updated: 2021/08/02 18:14:11 by sondho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*store_buff;
	size_t	index;
	size_t	s_index;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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

static size_t	ft_isnewline(char *s)
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

static void	update_store_buff(char ***s, size_t start)
{
	char	*new_s;
	size_t	index;
	size_t	len;

	len = ft_strlen(**s) - start;
	new_s = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_s)
		return ;
	index = 0;
	while (index < len)
	{
		new_s[index] = (**s)[index + start];
		index++;
	}
	free(**s);
	**s = NULL;
	**s = new_s;
}

static char	*get_line(char **s)
{
	char	*line;
	size_t	nl_index;
	size_t	index;

	nl_index = ft_isnewline(*s);
	index = 0;
	if (!nl_index)
	{
		line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (line);
	}
	nl_index--;
	line = (char *)ft_calloc(nl_index + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (index < nl_index)
	{
		line[index] = (*s)[index];
		index++;
	}
	update_store_buff(&s, nl_index + 1);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*store_buff;
	char		buff[BUFFER_SIZE + 1];
	ssize_t		rd_size;

	while (1)
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		if (rd_size <= 0)
			break ;
		buff[rd_size] = '\0';
		store_buff = ft_strjoin_gnl(store_buff, buff);
		if (!store_buff)
			return (ERROR);
		if (ft_isnewline(store_buff))
			break ;
	}
	if (rd_size == -1)
		return (ERROR);
	*line = get_line(&store_buff);
	if (!*line)
		return (ERROR);
	if (store_buff)
		return (SUCCESS);
	return (SUCCESS_EOF);
}
