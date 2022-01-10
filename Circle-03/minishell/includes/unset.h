/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:29:38 by hyun              #+#    #+#             */
/*   Updated: 2021/11/11 09:29:43 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "list_node.h"
# include "info.h"
# include "envp.h"
# include "export.h"
# include "../libft/includes/libft.h"
# include <stdbool.h>
# include <stdio.h>

int	unset(t_list *list, t_info *info);

#endif
