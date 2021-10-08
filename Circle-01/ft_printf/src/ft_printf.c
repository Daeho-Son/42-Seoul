/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:42:45 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 16:50:10 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_tag	*tag;
	va_list	ap;
	int		count;

	tag = (t_tag *)malloc(sizeof(t_tag));
	if (!tag)
		return (ERROR);
	va_start(ap, format);
	count = find_parse_format(format, tag, ap);
	if (count == ERROR)
		return (ERROR);
	va_end(ap);
	free(tag);
	tag = NULL;
	return (count);
}
