/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:39:39 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/21 16:26:48 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/export.h"

int	remove_envp_index(int idx, char **envp, t_info *info)
{
	int		i;
	int		it;
	char	**my_envp;

	i = -1;
	while (envp[++i])
		;
	my_envp = (char **)malloc(sizeof(char *) * i);
	if (my_envp == NULL)
		return (-1);
	i = -1;
	it = -1;
	while (envp[++i])
	{
		if (i != idx)
		{
			my_envp[++it] = ft_strdup(envp[i]);
			if (my_envp[it] == NULL)
				return (-1);
		}
	}
	my_envp[it + 1] = NULL;
	free_envp(envp);
	info->envp = my_envp;
	return (0);
}

int	remove_envp(char *data, char **envp, t_info *info)
{
	int	i;
	int	res;

	i = -1;
	while (envp[++i])
	{
		if (has_same_envp_key(data, envp[i]))
		{
			res = remove_envp_index(i, envp, info);
			if (res == -1)
				return (1);
			break ;
		}
	}
	return (0);
}

int	add_envp(char *var, char **envp, t_info *info)
{
	char	**new_envp;
	char	*dup_var;
	int		i;

	dup_var = ft_strdup(var);
	if (dup_var == NULL)
		return (1);
	i = -1;
	while (envp[++i])
		;
	new_envp = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (envp[++i])
		new_envp[i] = ft_strdup(envp[i]);
	new_envp[i] = dup_var;
	new_envp[i + 1] = 0;
	info->envp = new_envp;
	free_envp(envp);
	return (0);
}

int	divide_key_value(const char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '=' && str[i])
		;
	if (i == 0)
		return (1);
	if (str[i] == 0)
		return (2);
	return (0);
}

int	ft_export(t_list *list, t_info *info)
{
	t_node	*node;
	int		stat;
	id_t	res;

	node = list->start_node->next;
	stat = 0;
	while (node != 0)
	{
		res = divide_key_value(node->data);
		if (res == 0)
		{
			if (remove_envp(node->data, info->envp, info)
				|| add_envp(node->data, info->envp, info))
				return (1);
		}
		else if (res == 1)
		{
			printf("minishell: export: `%s': not a valid identifier\n",
				node->data);
			stat = 1;
		}
		node = node->next;
	}
	info->exit_status = stat;
	return (0);
}
