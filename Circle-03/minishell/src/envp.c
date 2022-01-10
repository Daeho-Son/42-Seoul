/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:35:39 by jongpark          #+#    #+#             */
/*   Updated: 2021/11/08 10:21:41 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envp.h"

char	*dup_envp_value(char *key, char **envp)
{
	int	i;
	int	it;

	i = -1;
	while (envp[++i])
	{
		if (has_same_envp_key(key, envp[i]))
		{
			it = -1;
			while (envp[i][++it] != '=')
				;
			return (ft_strdup(&envp[i][++it]));
		}
	}
	return (NULL);
}

bool	has_equal(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (true);
		str++;
	}
	return (false);
}

bool	has_same_envp_key(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] == '=' || b[i] == '=')
			return (true);
		if (a[i] != b[i])
			return (false);
		i++;
	}
	if (!a[i] && b[i] == '=')
		return (true);
	if (!b[i] && a[i] == '=')
		return (true);
	return (false);
}

char	**dup_envp(char **envp)
{
	int		i;
	char	**my_envp;

	i = -1;
	while (envp[++i])
		;
	my_envp = (char **)malloc(sizeof(char *) * (i + 1));
	if (my_envp == NULL)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		my_envp[i] = ft_strdup(envp[i]);
	}
	my_envp[i] = NULL;
	return (my_envp);
}

void	free_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		free(envp[i]);
	}
	free(envp);
}
