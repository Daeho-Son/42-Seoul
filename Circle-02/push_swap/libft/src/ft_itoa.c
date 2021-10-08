/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:38:21 by dason             #+#    #+#             */
/*   Updated: 2021/01/09 19:46:48 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*fill_str(unsigned int n, unsigned int end, int is_minus)
{
	char	*str;

	str = (char *)ft_calloc((end + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (--end > 0)
	{
		str[end] = (n % 10) + '0';
		n /= 10;
	}
	if (is_minus)
		str[end] = ('-');
	else
		str[end] = (n + '0');
	return (str);
}

static unsigned int	get_count(unsigned int n)
{
	unsigned int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	count;
	unsigned int	size;
	unsigned int	unsigned_n;
	int				is_minus;

	if (n < 0)
	{
		is_minus = 1;
		unsigned_n = -n;
	}
	else
	{
		is_minus = 0;
		unsigned_n = -n;
	}
	count = get_count(unsigned_n);
	if (is_minus)
		size = (count + 1);
	else
		size = count;
	return (fill_str(unsigned_n, size, is_minus));
}
