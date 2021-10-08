/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:28:15 by dason             #+#    #+#             */
/*   Updated: 2021/07/05 14:37:48 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./common.h"

typedef struct s_counts
{
	int				count;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
	int				rra_count;
	int				rrb_count;
}					t_counts;

void				clear_bundle(t_bundle *bundle, t_counts *counts);

int					get_arr(int **arr, t_stack *stack);

int					sort_stack(t_bundle *bundle);
void				sort_two_three(t_bundle *bundle, int reverse);
void				sort_three_plus(t_bundle *bundle);
void				sort_three_plus_reverse(t_bundle *bundle);
void				sort_four_five(t_bundle *bundle);
void				sort_above_seven(t_bundle *bundle);

void				a_to_b(t_bundle *bundle, int left, int right, int count);
void				b_to_a(t_bundle *bundle, int left, int right, int count);

void				to_top(t_bundle *bundle, t_counts *counts,
						t_node **node, char flag);
void				rotate_back(t_bundle *bundle, t_counts *counts, char flag);
void				b_to_a_all(t_bundle *bundle, int count);

#endif
