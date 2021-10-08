/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:47:52 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 22:06:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	if (dst == src || !len)
		return (dst);
	if (dst > src)
	{
		tmp_dst += len;
		tmp_src += len;
		while (len--)
			*--tmp_dst = *--tmp_src;
	}
	else
	{
		while (len--)
			*tmp_dst++ = *tmp_src++;
	}
	return (dst);
}
