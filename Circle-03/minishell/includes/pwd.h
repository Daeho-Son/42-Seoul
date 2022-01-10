/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:29:35 by hyun              #+#    #+#             */
/*   Updated: 2021/12/15 17:05:01 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWD_H
# define PWD_H

# include "list_node.h"
# include "info.h"
# include <unistd.h>
# include <stdio.h>

# define PATH_LENGTH 1024

int	pwd(t_info *info);

#endif
