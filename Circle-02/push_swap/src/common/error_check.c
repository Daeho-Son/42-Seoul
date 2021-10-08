/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:08:51 by dason             #+#    #+#             */
/*   Updated: 2021/07/05 14:38:59 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	char_check(char **s)
{
	int		index;

	while (*s)
	{
		index = -1;
		while ((*s)[++index])
		{
			if (index == 0 && (*s)[0] == '-')
				continue ;
			if (!ft_isdigit((*s)[index]))
				error();
		}
		s++;
	}
	return (1);
}

static int	ft_isduplicatie(int *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j])
				error();
			j++;
		}
		i++;
	}
	return (1);
}

int	dup_check(int argc, char **s)
{
	int		*tmp;
	int		data;
	int		index;
	int		tmp_index;

	tmp_index = 0;
	tmp = (int *)ft_calloc(argc, sizeof(int));
	if (!tmp)
		error();
	while (*s)
	{
		data = 0;
		index = -1;
		while ((*s)[++index])
			data = data * 10 + ((*s)[index] - '0');
		tmp[tmp_index++] = data;
		s++;
	}
	if (!ft_isduplicatie(tmp))
		error();
	free(tmp);
	tmp = NULL;
	return (1);
}

int	check_range(long long n)
{
	if (!(-2147483648 <= n && n <= 2147483647))
		return (0);
	return (1);
}
