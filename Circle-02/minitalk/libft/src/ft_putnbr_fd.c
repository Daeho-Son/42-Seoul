/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 01:12:18 by dason             #+#    #+#             */
/*   Updated: 2020/12/31 17:41:58 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	write_fd(unsigned int n, int fd)
{
	unsigned int	nbr;

	if (n >= 10)
		write_fd(n / 10, fd);
	nbr = (n % 10) + '0';
	write(fd, &nbr, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	write_fd((unsigned int)n, fd);
}
