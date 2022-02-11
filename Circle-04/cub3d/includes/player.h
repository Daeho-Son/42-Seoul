/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:16:09 by dason             #+#    #+#             */
/*   Updated: 2022/01/17 09:22:33 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vec2.h"
# include <stdbool.h>

typedef struct s_player
{
	t_vec2	p_direction;
	t_vec2	p_pos;
	bool	exist_player;
}	t_player;
#endif
