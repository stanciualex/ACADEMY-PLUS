/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_poh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:53:50 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:28:40 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*add_hash_prefix(t_printf *prt, char *str, char type, int len)
{
	if (prt->hash)
	{
		if (type == 'o' || type == 'O')
		{
			if (len != 1)
				str = ft_strjoin("0", str);
			else if (str[0] != '0')
				str = ft_strjoin("0", str);
		}
		if (type == 'x' && (len != 1 || prt->precision))
			str = ft_strjoin("0x", str);
		if (type == 'X' && (len != 1 || prt->precision))
			str = ft_strjoin("0X", str);
	}
	return (str);
}

void	print_pointer(t_printf *prt, char *str)
{
	char	c;

	c = (prt->zero) ? '0' : ' ';
	if (!str)
	{
		ft_putstr("(null)");
		prt->chrs += 6;
		return ;
	}
	str = ft_strdup(str);
	if (ft_strlen(str) == 1 && str[0] == '0'
		&& prt->is_precision && !prt->precision)
		str[0] = '\0';
	if (prt->zero && prt->width)
	{
		prt->width -= 2;
		if (prt->width < 0)
			prt->width = 0;
	}
	str = add_precision(prt, str);
	str = ft_strjoin("0x", str);
	str = add_width(prt, str, c);
	ft_putstr(str);
	prt->chrs += ft_strlen(str);
}

void	adjust_width(t_printf *prt, char type)
{
	if (prt->hash && prt->zero)
	{
		if (type == 'o' && prt->width > 0)
			prt->width--;
		else if (prt->width > 1)
			prt->width -= 2;
	}
}

void	print_octal_and_hex(t_printf *prt, char *str, char type)
{
	int		len;

	str = ft_strdup(str);
	len = ft_strlen(str);
	if (!str)
	{
		ft_putstr("(null)");
		prt->chrs += 6;
		return ;
	}
	if (prt->is_precision && !prt->precision && len == 1 && str[0] == '0')
		str[0] = '\0';
	adjust_width(prt, type);
	if (prt->is_precision && prt->precision)
		str = add_precision(prt, str);
	if (!prt->zero)
		str = add_hash_prefix(prt, str, type, len);
	str = add_width(prt, str, (prt->zero) ? '0' : ' ');
	if (prt->zero)
		str = add_hash_prefix(prt, str, type, len);
	if (type == 'X')
		str = ft_strupper(str);
	ft_putstr(str);
	prt->chrs += ft_strlen(str);
}
