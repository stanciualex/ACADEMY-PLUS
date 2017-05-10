/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:56:15 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:26:05 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_number(t_printf *prt, long long n)
{
	char	*str;

	str = ft_strnew(100);
	str = ft_lltoa_base(n, 10);
	if (prt->is_precision && !prt->precision
		&& ft_strlen(str) == 1 && str[0] == '0')
		str[0] = '\0';
	str = add_prefix(prt, str);
	str = add_precision(prt, str);
	str = add_width(prt, str, ' ');
	ft_putstr(str);
	prt->chrs += ft_strlen(str);
}

void	print_unumber(t_printf *prt, unsigned long long n)
{
	char	*str;

	str = ft_strnew(100);
	str = ft_ulltoa_base(n, 10);
	if (prt->is_precision && !prt->precision
		&& ft_strlen(str) == 1 && str[0] == '0')
		str[0] = '\0';
	str = add_precision(prt, str);
	str = add_width(prt, str, ' ');
	ft_putstr(str);
	prt->chrs += ft_strlen(str);
}

void	print_string(t_printf *prt, char *str)
{
	char	c;

	c = (prt->zero) ? '0' : ' ';
	if (!str)
	{
		str = ft_strnew(7);
		ft_strcpy(str, "(null)");
		if (prt->is_precision)
			str[prt->precision] = '\0';
	}
	str = ft_strdup(str);
	if (prt->is_precision && prt->precision < (int)ft_strlen(str))
		str[prt->precision] = '\0';
	str = add_width(prt, str, c);
	ft_putstr(str);
	prt->chrs += ft_strlen(str);
}

void	print_char(t_printf *prt, int c)
{
	char	*aux;
	char	w;

	w = prt->zero ? '0' : ' ';
	if (prt->width)
	{
		aux = char_fill(prt->width - 1, w);
		if (!prt->minus)
		{
			ft_putstr(aux);
			prt->chrs += ft_strlen(aux);
		}
	}
	ft_putchar(c);
	prt->chrs++;
	if (prt->minus && prt->width)
	{
		ft_putstr(aux);
		prt->chrs += ft_strlen(aux);
	}
}
