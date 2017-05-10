/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:03:29 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:23:53 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_decimal(t_printf *prt)
{
	if (prt->lflags.z)
		print_number(prt, va_arg(prt->ap, size_t));
	else if (prt->lflags.j)
		print_number(prt, va_arg(prt->ap, intmax_t));
	else if (prt->lflags.ll)
		print_number(prt, va_arg(prt->ap, long long int));
	else if (prt->lflags.l)
		print_number(prt, va_arg(prt->ap, long int));
	else if (prt->lflags.h)
		print_number(prt, (short int)va_arg(prt->ap, int));
	else if (prt->lflags.hh)
		print_number(prt, (signed char)va_arg(prt->ap, int));
	else
		print_number(prt, va_arg(prt->ap, int));
}

void	handle_string(t_printf *prt)
{
	if (prt->lflags.l)
		print_wstring(prt, va_arg(prt->ap, wchar_t*));
	else
		print_string(prt, va_arg(prt->ap, char*));
}

void	handle_char(t_printf *prt)
{
	if (prt->lflags.l)
		print_wchar(prt, va_arg(prt->ap, wint_t));
	else
		print_char(prt, va_arg(prt->ap, int));
}

void	handle_unsigned(t_printf *prt)
{
	if (prt->lflags.z)
		print_unumber(prt, va_arg(prt->ap, size_t));
	else if (prt->lflags.j)
		print_unumber(prt, va_arg(prt->ap, uintmax_t));
	else if (prt->lflags.ll)
		print_unumber(prt, va_arg(prt->ap, unsigned long long int));
	else if (prt->lflags.l)
		print_unumber(prt, va_arg(prt->ap, unsigned long int));
	else if (prt->lflags.h)
		print_unumber(prt, (unsigned short int)va_arg(prt->ap, unsigned int));
	else if (prt->lflags.hh)
		print_unumber(prt, (unsigned char)va_arg(prt->ap, unsigned int));
	else
		print_unumber(prt, va_arg(prt->ap, unsigned int));
}
