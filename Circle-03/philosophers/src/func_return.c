/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:48 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:49 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	return_time_to_die(unsigned long long time, int id)
{
	printf("%03llums %d died\n", time, id);
	return (0);
}

int	return_full(void)
{
	printf("Philosophers are full.\n");
	return (0);
}
