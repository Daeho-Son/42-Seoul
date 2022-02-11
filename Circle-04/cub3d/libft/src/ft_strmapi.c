/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:58:37 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 20:45:01 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	index;

	if (!s || !f)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s) + 1), 1);
	if (!str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = (*f)(index, s[index]);
		index++;
	}
	return (str);
}
