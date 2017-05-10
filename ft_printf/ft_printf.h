/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:39:53 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/15 17:54:18 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <inttypes.h>
# include "libft.h"

# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"

typedef struct		s_length_flags
{
	int				hh;
	int				h;
	int				ll;
	int				l;
	int				j;
	int				z;
}					t_length_flags;

typedef struct		s_printf
{
	va_list			ap;
	char			*str;
	int				chrs;
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				hash;
	int				width;
	int				precision;
	int				is_precision;
	t_length_flags	lflags;
}					t_printf;

/*
** ft_printf.c
*/
int					ft_printf(const char *restrict format, ...);
int					start(t_printf *prt);
void				init(t_printf *prt);
void				handle_str(t_printf *prt);

/*
** handle_flags.c
*/
void				handle_flags(t_printf *prt);
void				handle_width(t_printf *prt);
void				handle_precision(t_printf *prt);
void				handle_precision2(t_printf *prt);
void				handle_length_flags(t_printf *prt);

/*
** handle_specifiers1.c
*/
void				handle_octal_and_hex(t_printf *prt, int base, char type);
void				handle_specifier(t_printf *prt);
void				handle_specifier2(t_printf *prt);

/*
** handle_specifiers2.c
*/
void				handle_decimal(t_printf *prt);
void				handle_string(t_printf *prt);
void				handle_char(t_printf *prt);
void				handle_unsigned(t_printf *prt);

/*
** print_csd.c
*/
void				print_number(t_printf *prt, long long n);
void				print_unumber(t_printf *prt, unsigned long long n);
void				print_string(t_printf *prt, char *str);
void				print_char(t_printf *prt, int c);

/*
** print_poh.c
*/
char				*add_hash_prefix(t_printf *prt, char *str, char type,
																	int len);
void				print_pointer(t_printf *prt, char *str);
void				adjust_width(t_printf *prt, char type);
void				print_octal_and_hex(t_printf *prt, char *str, char type);

/*
** print_wc.c
*/
int					convert_precision(wchar_t *wstr, int n);
int					count_total_bits(wchar_t *wstr, int n);
void				print_wstring2(t_printf *prt, wchar_t *wstr, int total,
															int total_bits);
void				print_wstring(t_printf *prt, wchar_t *wstr);
void				print_wchar(t_printf *prt, wint_t wc);

/*
** print_aux.c
*/
int					nbr_bits(unsigned int nbr);
void				ft_putnwstr(wchar_t *wstr, int n);
void				ft_putnchar(char c, int size);

/*
** utils.c
*/
char				*char_fill(int n, int c);
char				*add_prefix(t_printf *prt, char *str);
char				*add_precision(t_printf *prt, char *str);
char				*add_width(t_printf *prt, char *str, char c);

/*
** colors.c
*/
void				check_color(t_printf *prt);
void				verify_color(t_printf *prt, char *color);
void				verify_color2(t_printf *prt, char *color);

#endif
