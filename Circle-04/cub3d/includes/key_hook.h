/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:35 by dason             #+#    #+#             */
/*   Updated: 2022/01/25 16:59:00 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

# include <math.h>
# include "info.h"
# include "render.h"
# include <stdio.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

int	key_hook(int keycode, t_info *info);
int	turn_right(t_info *info);
int	turn_left(t_info *info);

#endif
