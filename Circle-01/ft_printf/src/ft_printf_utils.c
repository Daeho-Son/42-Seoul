/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:24:28 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 15:07:29 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	if (c == 'n' || c == 'f' || c == 'g' || c == 'e' || c == 'o')
		return (c);
	return (0);
}

char	is_flag(char c)
{
	if (c == '-' || c == '0')
		return (c);
	return (0);
}

void	get_width(t_tag *tag, va_list ap, char *format_tag)
{
	int		n;
	int		index;

	n = 0;
	index = 0;
	if (format_tag[index] == '*')
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			tag->minus = 1;
			tag->width = n * (-1);
		}
		else
			tag->width = n;
	}
	if (ft_isdigit(format_tag[index]))
		tag->width = ft_atoi(&format_tag[index]);
}
