/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:25:28 by jongpark          #+#    #+#             */
/*   Updated: 2021/12/15 17:06:47 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pwd.h"

int	pwd(t_info *info)
{
	char	path[PATH_LENGTH];

	printf("%s\n", getcwd(path, PATH_LENGTH));
	info->exit_status = 0;
	return (0);
}
