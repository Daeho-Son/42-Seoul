/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:41 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:43 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (!checker(argc, argv))
		return (-1);
	philo = init(argc, argv);
	if (!philo_thread(philo))
		return (-1);
	return (monitor(philo));
}
