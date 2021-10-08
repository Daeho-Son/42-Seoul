/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:43:32 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 14:50:40 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_store_buff(char ***s, size_t start)
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

char	*get_line(char **s)
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

int	return_all(char *line, char *store_buff)
{
	if (!line)
		return (ERROR);
	if (store_buff)
		return (SUCCESS);
	else
		return (SUCCESS_EOF);
}

int	get_next_line(int fd, char **line)
{
	static char	*store_buff[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	ssize_t		rd_size;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (ERROR);
	while (1)
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		if (rd_size <= 0)
			break ;
		buff[rd_size] = '\0';
		store_buff[fd] = ft_strjoin(store_buff[fd], buff);
		if (!store_buff[fd])
			return (ERROR);
		if (ft_isnewline(store_buff[fd]))
			break ;
	}
	if (rd_size == -1)
		return (ERROR);
	*line = get_line(&store_buff[fd]);
	return (return_all(*line, store_buff[fd]));
}
