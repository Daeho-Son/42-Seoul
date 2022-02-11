/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:35:30 by hyun              #+#    #+#             */
/*   Updated: 2022/01/04 22:01:51 by hyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2	v2_plus(t_vec2 v1, t_vec2 v2)
{
	t_vec2	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

t_vec2	v2_minus(t_vec2 v1, t_vec2 v2)
{
	t_vec2	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

t_vec2	v2_scala(double a, t_vec2 v)
{
	t_vec2	res;

	res.x = a * v.x;
	res.y = a * v.y;
	return (res);
}
