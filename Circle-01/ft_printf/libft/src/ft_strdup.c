/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 13:52:06 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 20:39:53 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_s1;
	size_t	index;

	index = 0;
	tmp_s1 = (char *)ft_calloc((ft_strlen(s1) + 1), 1);
	if (!tmp_s1)
		return (NULL);
	while (s1[index])
	{
		tmp_s1[index] = s1[index];
		index++;
	}
	return (tmp_s1);
}
