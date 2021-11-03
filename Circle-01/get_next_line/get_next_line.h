/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:40:59 by dason             #+#    #+#             */
/*   Updated: 2021/02/06 19:41:46 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define ERROR -1
# define SUCCESS 1
# define SUCCESS_EOF 0

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
void	update_store_buff(char ***s, size_t n);
char	*get_line(char **s);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_isnewline(char *s);
char	*ft_strdup(char *s);
void	*ft_calloc(size_t count, size_t size);

#endif
