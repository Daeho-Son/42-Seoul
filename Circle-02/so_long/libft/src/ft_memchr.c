/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:30:08 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 20:16:00 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int value, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)value)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
