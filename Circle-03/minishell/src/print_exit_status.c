/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:20:24 by dason             #+#    #+#             */
/*   Updated: 2021/12/13 17:20:25 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/print_exit_status.h"

void	print_exit_status(t_info *info)
{
	ft_putnbr_fd(info->exit_status, 1);
	ft_putchar_fd('\n', 1);
}
