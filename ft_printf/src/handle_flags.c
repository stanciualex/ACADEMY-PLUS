/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:08:40 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/15 17:07:26 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	handle_flags(t_printf *prt)
{
	while (ft_strchr("-+ 0#", *(prt->str)))
	{
		if (!(*(prt->str)))
			return ;
		if (*(prt->str) == '-')
			prt->minus = 1;
		if (*(prt->str) == '+')
			prt->plus = 1;
		if (*(prt->str) == ' ')
			prt->space = 1;
		if (*(prt->str) == '0')
			prt->zero = 1;
		if (*(prt->str) == '#')
			prt->hash = 1;
		prt->str++;
	}
	if (prt->minus)
		prt->zero = 0;
}

void	handle_width(t_printf *prt)
{
	if (!(*(prt->str)))
		return ;
	if (*(prt->str) == '*')
	{
		prt->width = va_arg(prt->ap, int);
		prt->str++;
		if (prt->width < 0)
		{
			prt->width *= -1;
			prt->minus = 1;
		}
	}
	else
	{
		if (ft_isdigit(*(prt->str)) && prt->width)
			prt->width = 0;
		while (ft_isdigit(*(prt->str)))
		{
			prt->width = prt->width * 10 + (*(prt->str) - '0');
			prt->str++;
		}
	}
}

void	handle_precision2(t_printf *prt)
{
	prt->str++;
	if (prt->precision)
		prt->precision = 0;
	while (ft_isdigit(*(prt->str)))
	{
		prt->precision = prt->precision * 10 + (*(prt->str) - '0');
		prt->str++;
	}
}

void	handle_precision(t_printf *prt)
{
	if (!(*(prt->str)))
		return ;
	if (*(prt->str) == '.')
	{
		prt->is_precision = 1;
		if (ft_isdigit(*(prt->str + 1)))
			handle_precision2(prt);
		else if (*(prt->str) == '.' && *(prt->str + 1) == '*')
		{
			prt->precision = va_arg(prt->ap, int);
			if (prt->precision < 0)
			{
				prt->is_precision = 0;
				prt->precision = 0;
			}
			prt->str += 2;
		}
		else
		{
			prt->precision = 0;
			prt->str++;
		}
	}
}

void	handle_length_flags(t_printf *prt)
{
	if (!(*(prt->str)))
		return ;
	if (*(prt->str) == 'h' && *(prt->str + 1) == 'h')
	{
		prt->lflags.hh = 1;
		prt->str += 2;
	}
	else if (*(prt->str) == 'l' && *(prt->str + 1) == 'l')
	{
		prt->lflags.ll = 1;
		prt->str += 2;
	}
	else if (ft_strchr("hljz", *(prt->str)))
	{
		if (*(prt->str) == 'h')
			prt->lflags.h = 1;
		else if (*(prt->str) == 'l')
			prt->lflags.l = 1;
		else if (*(prt->str) == 'j')
			prt->lflags.j = 1;
		else if (*(prt->str) == 'z')
			prt->lflags.z = 1;
		prt->str++;
	}
}
