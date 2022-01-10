/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:29:18 by hyun              #+#    #+#             */
/*   Updated: 2021/11/11 09:29:49 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include <stdlib.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

char	**dup_envp(char **envp);
void	free_envp(char **envp);
bool	has_same_envp_key(char *a, char *b);
bool	has_equal(char *str);
char	*dup_envp_value(char *key, char **envp);

#endif
