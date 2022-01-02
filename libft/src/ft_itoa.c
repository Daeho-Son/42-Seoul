/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:38:21 by dason             #+#    #+#             */
/*   Updated: 2022/01/02 14:20:50 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*fill_str(unsigned int n, unsigned int len)
{
	char	*str;

	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	if (len == 1)
		str[0] = '-';
	return (str);
}

static unsigned int	get_len(unsigned int n, int len)
{
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	unsigned_n;

	len = 1;
	unsigned_n = n;
	if (n < 0)
	{
		len++;
		unsigned_n = n * -1;
	}
	len = get_len(unsigned_n, len);
	return (fill_str(unsigned_n, len));
}
