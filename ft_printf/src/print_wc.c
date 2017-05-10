/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:48:23 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:44:37 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		convert_precision(wchar_t *wstr, int n)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (wstr[i] && n > 0)
	{
		if (n - ft_sizeof_wchar(wstr[i]) < 0)
			break ;
		n -= ft_sizeof_wchar(wstr[i]);
		count++;
		i++;
	}
	return (count);
}

int		count_total_bits(wchar_t *wstr, int n)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (wstr[i] && i < n)
	{
		count += ft_sizeof_wchar(wstr[i]);
		i++;
	}
	return (count);
}

void	print_wstring2(t_printf *prt, wchar_t *wstr, int total, int total_bits)
{
	int		i;

	if (!prt->minus && prt->width > total_bits)
	{
		ft_putnchar((prt->zero ? '0' : ' '), prt->width - total_bits);
		prt->chrs += prt->width - total_bits;
	}
	if (!(prt->is_precision && !prt->precision))
	{
		if (prt->is_precision
				&& prt->precision <= count_total_bits(wstr, total))
		{
			i = -1;
			while (++i < prt->precision)
			{
				ft_putwchar(wstr[i]);
				prt->chrs += ft_sizeof_wchar(wstr[i]);
			}
		}
		else
		{
			ft_putwstr(wstr);
			prt->chrs += ft_wstrlen(wstr);
		}
	}
}

void	print_wstring(t_printf *prt, wchar_t *wstr)
{
	int		total;
	int		total_bits;

	if (!wstr)
	{
		ft_putstr("(null)");
		prt->chrs += 6;
		return ;
	}
	total = ft_wstrlen(wstr);
	if (prt->is_precision)
	{
		prt->precision = convert_precision(wstr, prt->precision);
		total = prt->precision;
	}
	total_bits = count_total_bits(wstr, total);
	print_wstring2(prt, wstr, total, total_bits);
	if (prt->minus && prt->width > total_bits)
	{
		ft_putnchar((prt->zero ? '0' : ' '), prt->width - total_bits);
		prt->chrs += prt->width - total_bits;
	}
}

void	print_wchar(t_printf *prt, wint_t wc)
{
	char	*aux;

	if (prt->width)
	{
		aux = char_fill(prt->width - 1, ' ');
		if (!prt->minus)
		{
			ft_putstr(aux);
			prt->chrs += ft_strlen(aux);
		}
	}
	ft_putwchar(wc);
	prt->chrs += ft_sizeof_wchar(wc);
	if (prt->minus && prt->width)
	{
		ft_putstr(aux);
		prt->chrs += ft_strlen(aux);
	}
}
