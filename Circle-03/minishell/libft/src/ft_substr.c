/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:53:41 by dason             #+#    #+#             */
/*   Updated: 2021/01/07 00:52:54 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp_s;
	size_t	index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		tmp_s = (char *)ft_calloc(1, sizeof(char));
		if (!tmp_s)
			return (NULL);
		return (tmp_s);
	}
	index = 0;
	tmp_s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!tmp_s)
		return (NULL);
	while (s[start] && index < len)
	{
		tmp_s[index] = s[start + index];
		index++;
	}
	return (tmp_s);
}
