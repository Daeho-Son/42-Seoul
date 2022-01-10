/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:29:10 by hyun              #+#    #+#             */
/*   Updated: 2021/11/11 09:29:52 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "list_node.h"
# include "info.h"
# include "envp.h"
# include <unistd.h>
# include <stdio.h>

int	cd(t_list *list, t_info *info);

#endif
