/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun <hyun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:29:26 by hyun              #+#    #+#             */
/*   Updated: 2021/12/14 11:28:17 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "list_node.h"
# include <termios.h>
# include <stdbool.h>

# define WRITE_END 1
# define READ_END 0

typedef struct s_info
{
	char			**envp;
	struct termios	orig_term;
	struct termios	new_term;
	int				pipe_in[2];
	int				pipe_out[2];
	int				l2_pipe[2];
	bool			has_pipe_in;
	bool			has_redirect_l1;
	bool			has_redirect_l2;
	bool			has_redirect_r1;
	bool			has_redirect_r2;
	char			*l1_path;
	char			*l2_eof_word;
	char			*r1_path;
	char			*r2_path;
	int				stdout_copy;
	int				stdin_copy;
	int				exit_status;
	t_node			*current_node;
}				t_info;

#endif
