/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:15:03 by dason             #+#    #+#             */
/*   Updated: 2021/07/15 20:15:04 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sigusr1_handler(int sig)
{
}

int	main(int argc, char *argv[])
{
	t_info	client_info;

	check_ar(argc, argv[1]);
	signal(SIGUSR1, sigusr1_handler);
	ft_memset(&client_info, 0, sizeof(t_info));
	client_info.server_pid = ft_atoi(argv[1]);
	send_msg(&client_info, argv[2]);
	return (0);
}
