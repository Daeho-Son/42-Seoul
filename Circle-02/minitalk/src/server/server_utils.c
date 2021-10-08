/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:14:44 by dason             #+#    #+#             */
/*   Updated: 2021/07/15 20:22:46 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	binary_to_decimal(int binary)
{
	int	decimal;
	int	weight;
	int	rem;

	decimal = 0;
	weight = 1;
	rem = 1;
	while (binary != 0)
	{
		rem = binary % 10;
		decimal += (rem * weight);
		binary /= 10;
		weight *= 2;
	}
	return (decimal);
}

void	print_msg(int binary)
{
	int	decimal;

	decimal = binary_to_decimal(binary);
	ft_putchar_fd(decimal, 1);
}
