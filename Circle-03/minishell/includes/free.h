/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:19:20 by dason             #+#    #+#             */
/*   Updated: 2021/11/29 17:29:44 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "list_node.h"

void	free_double_pointer(char ***s);
void	free_list(t_list *list);
void	free_list_node(t_list **list);

#endif
