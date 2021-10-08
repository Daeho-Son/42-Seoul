/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:43:01 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 15:58:15 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*dot_s(t_tag *tag, char *s)
{
	char	*new_s;

	new_s = ft_substr(s, 0, tag->precision);
	return (new_s);
}

static int	print_width(t_tag *tag, int len)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (index++ < tag->width - len)
		count += write(1, " ", 1);
	return (count);
}

int	format_s(t_tag *tag, va_list ap)
{
	int		count;
	char	*s;
	int		s_len;

	s_len = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	if (tag->dot && tag->precision >= 0)
		s = dot_s(tag, s);
	s_len = (int)ft_strlen(s);
	count = s_len;
	if (tag->minus)
		write(1, s, s_len);
	count += print_width(tag, s_len);
	if (!tag->minus)
		write(1, s, s_len);
	if (tag->dot && tag->precision >= 0)
	{
		free(s);
		s = NULL;
	}
	return (count);
}
