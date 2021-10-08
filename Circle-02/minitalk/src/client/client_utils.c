/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:15:07 by dason             #+#    #+#             */
/*   Updated: 2021/07/15 20:23:26 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	check_ar(int argc, char *server_pid)
{
	int	index;

	if (argc != 3)
		error("Three parameters are required.");
	index = -1;
	while (server_pid[++index])
	{
		if (!ft_isdigit(server_pid[index]))
			error("Enter only numbers for the first parameter.");
	}
}

void	decimal_to_binary(int *bit_set, int decimal)
{
	int		index;

	index = 8;
	while (decimal >= 1)
	{
		bit_set[--index] = decimal % 2;
		decimal = decimal / 2;
	}
}

void	send_msg(t_info *client_info, char *msg)
{
	int		m_index;
	int		index;

	m_index = -1;
	while (msg[++m_index])
	{
		ft_memset(&client_info->bit_set, 0, 8);
		decimal_to_binary(client_info->bit_set, msg[m_index]);
		index = -1;
		while (++index < 8)
		{
			if (client_info->bit_set[index] == 0)
				kill(client_info->server_pid, SIGUSR1);
			else if (client_info->bit_set[index] == 1)
				kill(client_info->server_pid, SIGUSR2);
			pause();
			usleep(10);
		}
	}
}
