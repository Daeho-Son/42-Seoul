/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:54:12 by dason             #+#    #+#             */
/*   Updated: 2020/12/30 15:34:20 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		index;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	str = (char *)ft_calloc((end - start + 2), sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (s1[index] && index < (end - start + 1))
	{
		str[index] = s1[start + index];
		index++;
	}
	return (str);
}
