/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:38:15 by dason             #+#    #+#             */
/*   Updated: 2021/01/01 20:48:33 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*char_s;
	int		s_len;

	char_s = (char *)s;
	s_len = ft_strlen(s);
	if (!c)
		return (char_s + s_len);
	while (s_len--)
	{
		if (char_s[s_len] == (char)c)
			return (char_s + s_len);
	}
	return (NULL);
}
