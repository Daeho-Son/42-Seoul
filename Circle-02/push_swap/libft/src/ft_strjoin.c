/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:29:52 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 20:42:38 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp_str;

	if (!s1 || !s2)
	{
		str = (char *)ft_calloc(1, 1);
		if (!str)
			return (NULL);
		return (str);
	}
	str = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!str)
		return (NULL);
	tmp_str = str;
	while (*s1)
		*tmp_str++ = *s1++;
	while (*s2)
		*tmp_str++ = *s2++;
	return (str);
}
