/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:36:20 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 15:58:39 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_itoa_hex(unsigned long long n)
{
	char				*str;
	unsigned long long	tmp_n;
	unsigned long long	end;
	unsigned long long	index;

	end = 1;
	tmp_n = n;
	while (tmp_n >= 16)
	{
		tmp_n /= 16;
		end++;
	}
	str = (char *)ft_calloc((end + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (--end > 0)
	{
		index = n % 16;
		str[end] = "0123456789abcdef"[index];
		n /= 16;
	}
	index = n % 16;
	str[end] = "0123456789abcdef"[index];
	return (str);
}

static int	print_width(t_tag *tag, int s_len)
{
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (index++ < tag->width - s_len - 2)
		count += write(1, " ", 1);
	return (count);
}

static int	print_s(char *s, int s_len)
{
	write(1, "0x", 2);
	write(1, s, s_len);
	return (s_len + 2);
}

int	format_p(t_tag *tag, va_list ap)
{
	int		count;
	char	*s;
	int		s_len;

	count = 0;
	s = ft_itoa_hex(va_arg(ap, unsigned long long));
	s_len = ft_strlen(s);
	if (s == NULL || (tag->dot && *s == '0' && !tag->precision))
	{
		s = 0;
		s_len = 0;
	}
	if (tag->minus)
		count += print_s(s, s_len);
	count += print_width(tag, s_len);
	if (!tag->minus)
		count += print_s(s, s_len);
	free(s);
	s = NULL;
	return (count);
}
