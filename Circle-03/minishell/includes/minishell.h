/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongpark <jongpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:29:31 by hyun              #+#    #+#             */
/*   Updated: 2021/12/23 13:17:25 by jongpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include "list_node.h"
# include "info.h"
# include "envp.h"
# include "env.h"
# include "parser.h"
# include "export.h"
# include "unset.h"
# include "pwd.h"
# include "cd.h"
# include "echo.h"
# include "free.h"
# include "print_exit_status.h"
# include "executable.h"
# include <stdio.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/wait.h>

# define PATH_LENGTH 1024
# define LOGO_PATH "etc/logo.txt"
# define LOGO_LENGTH 1024
# define INPUT_BUFFER_SIZE 1024
# define STAT_CTRL_D 3
# define STAT_CTRL_C 4

/*
**	MAIN
*/
int		init_minishell(t_info *info, char **envp, int argc, char **argv);
char	**make_argv_with_node(t_list *list);

/*
**	UTILS
*/
bool	is_blank(char *str);
bool	is_valid_input(char *str);
void	swap_pipe(t_info *info);
char	*get_eof_input(void);

/*
**	EXECUTE
*/
int		ft_exit(t_list *list, t_info *info);
int		execute_non_builtin(\
		t_list *list, char **argv, char **envp, t_info *info);

/*
**	SIGNAL
*/
void	handle_signal(int sig);
void	set_signal_child(void);
void	set_signal_parent(void);
void	set_signal_non_built_in(void);
void	set_stty(t_info *info);

/*
**	INPUT
*/
int		get_exit_result(int stat);
char	*get_user_input(t_info *info);

/*
**	REDIRECT
*/
void	swap_pipe(t_info *info);
void	handle_redirect(t_list *list, t_info *info);

/*
**	EXECUTE BUILT-IN
*/
int		try_exec_builtin(t_list *list, t_info *info);

/*
**	TEST
*/
char	*get_eof_input(void);

/*
**	preprocess
*/
int		preprocess(t_list *list, t_info *info);
void	preprocess_pipe_write(t_info *info);
void	preprocess_pipe_read(t_info *info);
int		preprocess_l1(t_info *info);
int		preprocess_l2(t_info *info);
void	preprocess_r1(t_info *info);
void	preprocess_r2(t_info *info);

/*
**	postprocess
*/
void	postprocess(t_info *info);
void	postprocess_builtin(t_list *list, t_info *info);

#endif
