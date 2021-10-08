/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:12:57 by dason             #+#    #+#             */
/*   Updated: 2021/07/15 20:24:28 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_info
{
	int		server_pid;
	int		bit_set[8];
}			t_info;

/*
**	common
*/
void	error(char *msg);

/*
**	server
*/
int		binary_to_decimal(int binary);
void	print_msg(int binary);

/*
**	client
*/
void	check_ar(int argc, char *server_pid);
void	decimal_to_binary(int *bit_set, int decimal);
void	send_msg(t_info *client_info, char *msg);

#endif
