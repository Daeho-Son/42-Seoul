/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:49:54 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 16:02:39 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*fill_str(unsigned int n, unsigned int end)
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
	str[end] = n + '0';
	return (str);
}

static char	*ft_itoa_di(int n)
{
	unsigned int	end;
	unsigned int	unsigned_n;
	unsigned int	tmp_n;

	if (n < 0)
		unsigned_n = -n;
	else
		unsigned_n = n;
	tmp_n = unsigned_n;
	end = 1;
	while (tmp_n >= 10)
	{
		tmp_n /= 10;
		end++;
	}
	return (fill_str(unsigned_n, end));
}

static int	print_width(t_tag *tag, int nbr_len, int is_minus)
{
	int		index;
	int		count;
	int		len;
	char	space;

	index = 0;
	count = 0;
	if (tag->zero && !tag->minus && (!tag->dot || tag->precision < 0))
		space = '0';
	else
		space = ' ';
	if (nbr_len < tag->precision)
		len = tag->width - tag->precision;
	else
		len = tag->width - nbr_len;
	if (is_minus && space == '0')
	{
		count += write(1, "-", 1);
		index++;
	}
	else if (is_minus && space != '0')
		len--;
	while (index++ < len)
		count += write(1, &space, 1);
	return (count);
}

static int	print_nbr(t_tag *tag, char *nbr, int nbr_len, int is_minus)
{
	int		count;
	int		index;

	count = nbr_len;
	index = 0;
	if (is_minus)
	{
		if (!(tag->zero && !tag->minus && (!tag->dot || tag->precision < 0)))
			count += write(1, "-", 1);
	}
	while (index++ < tag->precision - nbr_len)
		count += write(1, "0", 1);
	write(1, nbr, nbr_len);
	return (count);
}

int	format_di(t_tag *tag, va_list ap)
{
	int		count;
	char	*nbr;
	int		nbr_len;
	int		is_minus;
	int		n;

	n = va_arg(ap, int);
	is_minus = 0;
	if (n < 0)
		is_minus = 1;
	nbr = ft_itoa_di(n);
	nbr_len = (int)ft_strlen(nbr);
	if (tag->dot && !ft_strncmp(nbr, "0", nbr_len) && !(tag->precision < 0))
	{
		nbr = NULL;
		nbr_len = 0;
	}
	count = 0;
	if (tag->minus)
		count += print_nbr(tag, nbr, nbr_len, is_minus);
	count += print_width(tag, nbr_len, is_minus);
	if (!tag->minus)
		count += print_nbr(tag, nbr, nbr_len, is_minus);
	free(nbr);
	return (count);
}
