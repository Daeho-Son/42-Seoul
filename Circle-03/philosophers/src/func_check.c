/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:32:58 by dason             #+#    #+#             */
/*   Updated: 2021/10/30 16:32:59 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_num(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '\0'
			|| argv[1][0] == '0')
		{
			printf("Please enter the correct number.\n");
			return (0);
		}
		while (argv[i][++j] != '\0')
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
			{
				printf("Please enter the correct number.\n");
				return (0);
			}
		}
	}
	return (1);
}

int	check_param(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("The number of parameters is not correct.");
		return (0);
	}
	return (1);
}

int	check_range(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) != num_of_digit(get_num(argv[i])))
		{
			printf("The range of numbers is strange.\n");
			return (0);
		}
	}
	return (1);
}

int	checker(int argc, char **argv)
{
	if (!check_param(argc))
		return (0);
	if (!check_num(argc, argv))
		return (0);
	if (!check_range(argc, argv))
		return (0);
	return (1);
}
