/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_parse_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:28:18 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 17:04:54 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	formatter(t_tag *tag, va_list ap)
{
	int		count;
	char	specifier;

	count = 0;
	specifier = tag->specifier;
	if (specifier == 'c' || specifier == '%')
		count = format_c_per(tag, ap);
	if (specifier == 's')
		count = format_s(tag, ap);
	if (specifier == 'u' || specifier == 'x' || specifier == 'X')
		count = format_ux(tag, ap, specifier);
	if (specifier == 'd' || specifier == 'i')
		count = format_di(tag, ap);
	if (specifier == 'p')
		count = format_p(tag, ap);
	return (count);
}

static int	checker(char *format_tag)
{
	int		index;

	index = 0;
	while (is_flag(format_tag[index]))
		index++;
	while (ft_isdigit(format_tag[index]) || format_tag[index] == '*')
		index++;
	if (format_tag[index] == '.')
	{
		index++;
		while (ft_isdigit(format_tag[index]) || format_tag[index] == '*')
			index++;
	}
	if (is_specifier(format_tag[index]))
		return (1);
	return (0);
}

static int	parser(char *format_tag, t_tag *tag, va_list ap)
{
	int		index;
	char	*dot;

	if (!format_tag || !checker(format_tag))
		return (ERROR);
	index = -1;
	while (is_flag(format_tag[++index]))
	{
		if (format_tag[index] == '-')
			tag->minus = 1;
		else
			tag->zero = 1;
	}
	get_width(tag, ap, &format_tag[index]);
	dot = ft_strchr(format_tag, '.');
	if (dot)
	{
		tag->dot = 1;
		if (*(dot + 1) == '*')
			tag->precision = va_arg(ap, int);
		else
			tag->precision = ft_atoi(dot + 1);
	}
	tag->specifier = format_tag[ft_strlen(format_tag) - 1];
	return (SUCCESS);
}

static int	parse_format(const char *format, int len, t_tag *tag, va_list ap)
{
	char	*format_tag;
	int		count;

	format_tag = ft_substr(format, 0, len);
	if (parser(format_tag, tag, ap) == ERROR)
		return (ERROR);
	count = formatter(tag, ap);
	if (count == ERROR)
		return (ERROR);
	free(format_tag);
	format_tag = NULL;
	return (count);
}

int	find_parse_format(const char *format, t_tag *tag, va_list ap)
{
	int		index;
	int		len;
	int		count;
	int		tmp;

	index = -1;
	count = 0;
	while (format[++index])
	{
		if (format[index] == '%')
		{
			len = 1;
			index++;
			ft_memset(tag, 0, sizeof(t_tag));
			while (!is_specifier(format[index]) && len++)
				index++;
			tmp = parse_format(&format[index - len + 1], len, tag, ap);
			if (tmp == ERROR)
				return (ERROR);
			count += tmp;
		}
		else
			count += write(1, &format[index], 1);
	}
	return (count);
}
