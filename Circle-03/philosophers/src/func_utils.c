/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:44 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:45 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_ms(void)
{
	struct timeval		time;
	unsigned long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

unsigned long long	get_num(char *s)
{
	int					i;
	unsigned long long	n;

	n = 0;
	i = -1;
	while (s[++i] != '\0')
		n = (n * 10) + (s[i] - '0');
	return (n);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

size_t	num_of_digit(unsigned long long n)
{
	size_t	count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
