/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:35:14 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 16:12:20 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static char	*ft_itoa_x(unsigned int n, char specifier)
{
	char			*str;
	unsigned int	tmp_n;
	unsigned int	end;
	unsigned int	index;

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
	while ((int)--end >= 0)
	{
		index = n % 16;
		if (specifier == 'x')
			str[end] = "0123456789abcdef"[index];
		else
			str[end] = "0123456789ABCDEF"[index];
		n /= 16;
	}
	return (str);
}

static char	*ft_itoa_u(unsigned int n)
{
	char			*str;
	unsigned int	tmp_n;
	unsigned int	end;

	end = 1;
	tmp_n = n;
	while (tmp_n >= 10)
	{
		tmp_n /= 10;
		end++;
	}
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

static int	print_width(t_tag *tag, int nbr_len)
{
	int		index;
	int		count;
	int		len;
	char	space;

	index = 0;
	count = 0;
	if (tag->zero && !tag->minus
		&& (!tag->dot || (tag->dot && tag->precision < 0)))
		space = '0';
	else
		space = ' ';
	if (nbr_len < tag->precision)
		len = tag->width - tag->precision;
	else
		len = tag->width - nbr_len;
	while (index++ < len)
		count += write(1, &space, 1);
	return (count);
}

static int	print_precision_nbr(t_tag *tag, char *nbr, int nbr_len)
{
	int		count;
	int		index;

	count = nbr_len;
	index = 0;
	while (index++ < tag->precision - nbr_len)
		count += write(1, "0", 1);
	write(1, nbr, nbr_len);
	return (count);
}

int	format_ux(t_tag *tag, va_list ap, char specifier)
{
	int		count;
	char	*nbr;
	int		nbr_len;

	if (specifier == 'u')
		nbr = ft_itoa_u(va_arg(ap, unsigned int));
	else
		nbr = ft_itoa_x(va_arg(ap, unsigned int), specifier);
	if (!nbr)
		return (ERROR);
	nbr_len = (int)ft_strlen(nbr);
	if (tag->dot && !ft_strncmp(nbr, "0", nbr_len) && !(tag->precision < 0))
	{
		nbr = NULL;
		nbr_len = 0;
	}
	count = 0;
	if (tag->minus)
		count += print_precision_nbr(tag, nbr, nbr_len);
	count += print_width(tag, nbr_len);
	if (!(tag->minus))
		count += print_precision_nbr(tag, nbr, nbr_len);
	free(nbr);
	nbr = NULL;
	return (count);
}
