/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:04:16 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 19:34:37 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp_dst;

	tmp_dst = (char *)dst;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (tmp_dst);
}
