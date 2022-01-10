/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_organize_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:09:19 by dason             #+#    #+#             */
/*   Updated: 2021/12/24 11:56:23 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*combine_nodedata_env(t_info *info, char *data, int *i, int *new_i)
{
	char	*new_data;
	char	*env_value;
	size_t	size;

	env_value = get_env_value(&data[*i], info, i);
	--(*i);
	size = ft_strlen(data) + \
		   ft_strlen(env_value) + ft_strlen(info->current_node->data);
	new_data = (char *)ft_calloc(size, sizeof(char));
	if (!new_data)
		exit(1);
	ft_strlcat(new_data, info->current_node->data, \
		ft_strlen(info->current_node->data) + 1);
	free(info->current_node->data);
	if (env_value != NULL)
	{
		ft_strlcat(new_data, env_value, size);
		free(env_value);
	}
	(*new_i) = ft_strlen(new_data);
	return (new_data);
}

static void	process_quote_in_node(t_info *info, char *data, int *i, int *new_i)
{
	int		quote;

	quote = data[*i];
	while (data[++(*i)])
	{
		if (data[*i] == quote)
			break ;
		if (quote == '\"' && data[*i] == '$')
			info->current_node->data = \
				combine_nodedata_env(info, data, i, new_i);
		else if (data[*i] != quote)
			info->current_node->data[(*new_i)++] = data[*i];
	}
}

static void	progress_space(t_info *info, char *data, int *new_i)
{
	info->current_node->next = ft_create_node(NTYPE_STRING, \
		(char *)ft_calloc(ft_strlen(data) + 1, sizeof(char)));
	info->current_node = info->current_node->next;
	*new_i = 0;
}

void	organize_node(t_list *list, t_info *info)
{
	char	*data;
	int		i;
	int		new_i;

	info->current_node = list->start_node;
	data = ft_strdup(list->start_node->data);
	ft_memset(info->current_node->data, 0, ft_strlen(info->current_node->data));
	i = -1;
	new_i = 0;
	while (data[++i])
	{
		if (is_quote(data[i]) == false && data[i] != ' ' && data[i] != '$')
			info->current_node->data[new_i++] = data[i];
		else if (data[i] == ' ')
			progress_space(info, data, &new_i);
		else if (is_quote(data[i]))
			process_quote_in_node(info, data, &i, &new_i);
		else if (data[i] == '$')
			info->current_node->data = \
				combine_nodedata_env(info, data, &i, &new_i);
	}
	free(data);
}
