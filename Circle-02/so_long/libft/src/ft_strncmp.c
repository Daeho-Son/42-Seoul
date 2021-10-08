/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:59:20 by dason             #+#    #+#             */
/*   Updated: 2021/01/01 20:41:53 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (!n)
		return (0);
	while ((s1[index] == s2[index])
		&& (s1[index] && s2[index] && index < n - 1))
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
