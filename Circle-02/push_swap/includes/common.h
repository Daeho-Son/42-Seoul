/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:28:08 by dason             #+#    #+#             */
/*   Updated: 2021/07/05 14:37:04 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	char			name;
	struct s_node	*top;
	int				count;
	int				current;
}					t_stack;

typedef struct s_bundle
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				*arr;
}					t_bundle;

void				error(void);
int					char_check(char **argv);
int					dup_check(int argc, char **argv);
int					check_range(long long n);

t_node				*create_node(char *s);
int					init_stack(t_stack **stack, char name, char **s);

t_node				*pop(t_stack *stack);
void				add_last_node(t_stack *stack, t_node *new_node);
t_node				*get_last_node(t_stack *stack);

int					command_s(t_bundle *bundle, char *buff);
int					command_p(t_bundle *bundle, char *buff);
int					command_r(t_bundle *bundle, char *buff);
int					command_rr(t_bundle *bundle, char *buff);

void				func_swap(t_stack *stack);
void				func_push(t_stack *src, t_stack *dest);
void				func_rotate(t_stack *stack);
void				func_reverse_rotate(t_stack *stack);

int					check_sort_status(t_stack *stack_a);

void				free_all(t_bundle **bundle, char ***s);

#endif
