/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:10:42 by dason             #+#    #+#             */
/*   Updated: 2021/02/28 16:43:11 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	size_t	result;
	int		is_minus;

	result = 0;
	is_minus = 0;
	while (str && *str)
	{
		while (('\t' <= *str && *str <= '\r') || *str == ' ')
			str++;
		if ((*str == '-' || *str == '+') && (*str++ == '-'))
			is_minus = 1;
		while ('0' <= *str && *str <= '9')
			result = (*str++ - '0') + (result * 10);
		if ((result > LLONG_MAX) && is_minus == 0)
			return (-1);
		if ((result > LLONG_MAX) && is_minus == 1)
			return (0);
		if ((*str < '0' || '9' < *str) && is_minus)
			return (-result);
		if ((*str < '0' || '9' < *str) && !is_minus)
			return (result);
		str++;
	}
	return (0);
}
