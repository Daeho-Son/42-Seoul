/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dason <dason@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:42:58 by dason             #+#    #+#             */
/*   Updated: 2021/07/06 16:29:16 by dason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

# define SUCCESS 0
# define ERROR -1

typedef struct s_tag
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	char		specifier;
}				t_tag;

int				ft_printf(const char *format, ...);

int				find_parse_format(const char *format, t_tag *tag, va_list ap);

char			is_specifier(char c);
char			is_flag(char c);
void			get_width(t_tag *tag, va_list ap, char *format_tag);

int				format_c_per(t_tag *tag, va_list ap);
int				format_s(t_tag *tag, va_list ap);
int				format_ux(t_tag *tag, va_list ap, char specifier);
int				format_di(t_tag *tag, va_list ap);
int				format_p(t_tag *tag, va_list ap);

#endif
