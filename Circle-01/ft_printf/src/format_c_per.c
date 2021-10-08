/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:47:24 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 16:01:02 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_width(t_tag *tag)
{
	int		index;
	int		count;
	char	space;

	if (tag->zero && !tag->minus)
		space = '0';
	else
		space = ' ';
	index = 0;
	count = 0;
	while (index++ < tag->width - 1)
		count += write(1, &space, 1);
	return (count);
}

int	format_c_per(t_tag *tag, va_list ap)
{
	char	c;
	int		count;

	if (tag->specifier == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	count = 1;
	if (tag->minus)
		write(1, &c, 1);
	count += print_width(tag);
	if (!tag->minus)
		write(1, &c, 1);
	return (count);
}
