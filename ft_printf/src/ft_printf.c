/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:39:31 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/15 17:06:35 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init(t_printf *prt)
{
	prt->minus = 0;
	prt->plus = 0;
	prt->space = 0;
	prt->zero = 0;
	prt->hash = 0;
	prt->width = 0;
	prt->precision = 0;
	prt->is_precision = 0;
	prt->lflags.hh = 0;
	prt->lflags.h = 0;
	prt->lflags.ll = 0;
	prt->lflags.l = 0;
	prt->lflags.j = 0;
	prt->lflags.z = 0;
}

int		check_flags(t_printf *prt)
{
	return (prt->minus || prt->plus || prt->space || prt->zero || prt->hash ||
		prt->width || prt->precision || prt->is_precision || prt->lflags.hh ||
		prt->lflags.h || prt->lflags.ll || prt->lflags.l || prt->lflags.j ||
		prt->lflags.z);
}

void	handle_str(t_printf *prt)
{
	while (*(prt->str) && ft_strchr("-+ #.*0123456789hljz", *(prt->str)))
	{
		handle_flags(prt);
		handle_width(prt);
		handle_precision(prt);
		handle_length_flags(prt);
		if (!(*(prt->str + 1)) && !check_flags(prt))
			return ;
	}
	handle_specifier(prt);
	if (!(*(prt->str)))
		prt->str--;
}

int		start(t_printf *prt)
{
	while (*(prt->str))
	{
		if (*(prt->str) == '{')
			check_color(prt);
		if (*(prt->str) == '%')
		{
			init(prt);
			prt->str++;
			if (*(prt->str) == '\0')
				return (0);
			handle_str(prt);
		}
		else
		{
			ft_putchar(*(prt->str));
			prt->chrs++;
		}
		prt->str++;
	}
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	t_printf	prt;

	va_start(prt.ap, format);
	prt.str = (char*)format;
	if (!ft_strlen(prt.str))
		return (0);
	prt.chrs = 0;
	start(&prt);
	va_end(prt.ap);
	return (prt.chrs);
}
