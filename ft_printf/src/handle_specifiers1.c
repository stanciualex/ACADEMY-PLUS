/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:02:26 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:16:40 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_octal_and_hex(t_printf *prt, int base, char type)
{
	if (prt->lflags.z)
		print_octal_and_hex(prt, ft_ulltoa_base(va_arg(prt->ap,
			size_t), base), type);
	else if (prt->lflags.j)
		print_octal_and_hex(prt, ft_ulltoa_base(va_arg(prt->ap,
			uintmax_t), base), type);
	else if (prt->lflags.ll)
		print_octal_and_hex(prt, ft_ulltoa_base(va_arg(prt->ap,
			unsigned long long int), base), type);
	else if (prt->lflags.l)
		print_octal_and_hex(prt, ft_ulltoa_base(va_arg(prt->ap,
			unsigned long int), base), type);
	else if (prt->lflags.h)
		print_octal_and_hex(prt, ft_ulltoa_base((unsigned short int)
			va_arg(prt->ap, unsigned int), base), type);
	else if (prt->lflags.hh)
		print_octal_and_hex(prt, ft_ulltoa_base((unsigned char)va_arg(prt->ap,
			unsigned int), base), type);
	else
		print_octal_and_hex(prt, ft_ulltoa_base(va_arg(prt->ap,
			unsigned int), base), type);
}

void	handle_specifier2(t_printf *prt)
{
	if (*(prt->str) == 'u')
		handle_unsigned(prt);
	else if (*(prt->str) == 'U')
		print_unumber(prt, va_arg(prt->ap, unsigned long));
	else if (*(prt->str) == 'x')
		handle_octal_and_hex(prt, 16, 'x');
	else if (*(prt->str) == 'X')
		handle_octal_and_hex(prt, 16, 'X');
	else if (*(prt->str) == 'c')
		handle_char(prt);
	else if (*(prt->str) == 'C')
		print_wchar(prt, va_arg(prt->ap, wint_t));
	else
		print_char(prt, *(prt->str));
}

void	handle_specifier(t_printf *prt)
{
	if (!(*(prt->str)))
		return ;
	if (*(prt->str) == '%')
		print_char(prt, '%');
	else if (*(prt->str) == 's')
		handle_string(prt);
	else if (*(prt->str) == 'S')
		print_wstring(prt, va_arg(prt->ap, wchar_t*));
	else if (*(prt->str) == 'p')
		print_pointer(prt,
			ft_lltoa_base((long long)(va_arg(prt->ap, void*)), 16));
	else if (*(prt->str) == 'd' || *(prt->str) == 'i')
		handle_decimal(prt);
	else if (*(prt->str) == 'D')
		print_number(prt, va_arg(prt->ap, long));
	else if (*(prt->str) == 'o')
		handle_octal_and_hex(prt, 8, 'o');
	else if (*(prt->str) == 'O')
		print_octal_and_hex(prt,
			ft_ulltoa_base(va_arg(prt->ap, unsigned long), 8), 'O');
	else
		handle_specifier2(prt);
}
