/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:52:38 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 14:53:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define ERROR -1
# define SUCCESS 1
# define SUCCESS_EOF 0

int		get_next_line(int fd, char **line);
void	update_store_buff(char ***s, size_t n);
char	*get_line(char **s);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_isnewline(char *s);
char	*ft_strdup(char *s);
void	*ft_calloc(size_t count, size_t size);

#endif
