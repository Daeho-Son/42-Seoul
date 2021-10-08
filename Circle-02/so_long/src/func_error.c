/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:13:52 by dason             #+#    #+#             */
/*   Updated: 2021/10/04 20:13:54 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(char *msg)
{
	ft_putendl_fd("### ERROR ###", 2);
	ft_putstr_fd("Message: ", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}
