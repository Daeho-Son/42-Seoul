/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:43:10 by dason             #+#    #+#             */
/*   Updated: 2021/12/23 10:43:14 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*ft_getenv(char **envp, char *env_variable)
{
	char	*env_value;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(env_variable, envp[i], ft_strlen(env_variable)))
		{
			env_value = ft_strdup(&envp[i][ft_strlen(env_variable) + 1]);
			return (env_value);
		}
	}
	return (NULL);
}

static char	*get_env_variable(char *str, int *i)
{
	char	*env_variable;
	int		len;

	if (str[1] == '?')
		len = 2;
	else
	{
		len = 1;
		while (str[len])
		{
			if (!ft_isalnum(str[len]) && str[len] != '_')
				break ;
			if (str[len] == ' ' || str[len] == '\"' || str[len] == '\'')
				break ;
			len++;
		}
		if (len == 1)
		{
			*i += 1;
			return (NULL);
		}
	}
	*i += len;
	env_variable = ft_substr(str, 1, len - 1);
	return (env_variable);
}

char	*get_env_value(char *str, t_info *info, int *i)
{
	char	*env_value;
	char	*env_variable;

	env_variable = get_env_variable(str, i);
	if (env_variable == NULL)
	{
		env_value = ft_strdup("$");
		if (!env_value)
			exit (1);
	}
	else if (*env_variable == '?')
	{
		env_value = ft_itoa(info->exit_status);
		if (!env_value)
			exit (1);
	}
	else
		env_value = ft_getenv(info->envp, env_variable);
	free(env_variable);
	return (env_value);
}
