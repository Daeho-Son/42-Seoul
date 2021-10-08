/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:08:47 by dason             #+#    #+#             */
/*   Updated: 2021/07/05 14:38:34 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/common.h"
#include "../../includes/push_swap.h"

int	command_s(t_bundle *bundle, char *buff)
{
	if (!ft_strncmp(buff, "sa", 2))
	{
		write(1, "sa\n", 3);
		func_swap(bundle->stack_a);
		return (1);
	}
	else if (!ft_strncmp(buff, "sb", 2))
	{
		write(1, "sb\n", 3);
		func_swap(bundle->stack_b);
		return (1);
	}
	else if (!ft_strncmp(buff, "ss", 2))
	{
		write(1, "ss\n", 3);
		func_swap(bundle->stack_a);
		func_swap(bundle->stack_b);
		return (1);
	}
	else
		error();
	return (0);
}

int	command_p(t_bundle *bundle, char *buff)
{
	if (!ft_strncmp(buff, "pa", 2))
	{
		write(1, "pa\n", 3);
		func_push(bundle->stack_b, bundle->stack_a);
		return (1);
	}
	else if (!ft_strncmp(buff, "pb", 2))
	{
		write(1, "pb\n", 3);
		func_push(bundle->stack_a, bundle->stack_b);
		return (1);
	}
	else
		error();
	return (0);
}

int	command_r(t_bundle *bundle, char *buff)
{
	if (!ft_strncmp(buff, "ra", 2))
	{
		write(1, "ra\n", 3);
		func_rotate(bundle->stack_a);
		return (1);
	}
	else if (!ft_strncmp(buff, "rb", 2))
	{
		write(1, "rb\n", 3);
		func_rotate(bundle->stack_b);
		return (1);
	}
	else if (!ft_strncmp(buff, "rr", 2))
	{
		write(1, "rr\n", 3);
		func_rotate(bundle->stack_a);
		func_rotate(bundle->stack_b);
		return (1);
	}
	else
		error();
	return (0);
}

int	command_rr(t_bundle *bundle, char *buff)
{
	if (!ft_strncmp(buff, "rra", 3))
	{
		write(1, "rra\n", 4);
		func_reverse_rotate(bundle->stack_a);
		return (1);
	}
	else if (!ft_strncmp(buff, "rrb", 3))
	{
		write(1, "rrb\n", 4);
		func_reverse_rotate(bundle->stack_b);
		return (1);
	}
	else if (!ft_strncmp(buff, "rrr", 3))
	{
		write(1, "rrr\n", 4);
		func_reverse_rotate(bundle->stack_a);
		func_reverse_rotate(bundle->stack_b);
		return (1);
	}
	else
		error();
	return (0);
}
