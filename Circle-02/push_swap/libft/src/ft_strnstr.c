/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:42:57 by dason             #+#    #+#             */
/*   Updated: 2021/01/01 20:42:34 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s1_index;
	size_t	s2_index;

	s1_index = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[s1_index] && s1_index < len)
	{
		s2_index = 0;
		while (s1[s1_index + s2_index]
			&& (s1[s1_index + s2_index] == s2[s2_index])
			&& (s1_index + s2_index < len))
			s2_index++;
		if (!s2[s2_index])
			return ((char *)&s1[s1_index]);
		s1_index++;
	}
	return (NULL);
}
