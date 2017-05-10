/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:44:30 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:51:52 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*char_fill(int n, int c)
{
	int		i;
	char	*str;

	str = ft_strnew(100);
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*add_prefix(t_printf *prt, char *str)
{
	char	*prefix;

	if (ft_isdigit(*str))
	{
		prefix = NULL;
		if (prt->plus)
			prefix = "+";
		else if (prt->space)
			prefix = " ";
		if (prefix)
			str = ft_strjoin(prefix, str);
	}
	return (str);
}

char	*add_precision(t_printf *prt, char *str)
{
	int		len;
	int		width;
	int		is_prefix;
	char	*aux;

	len = ft_strlen(str);
	is_prefix = !ft_isdigit(*str) ? 1 : 0;
	width = (prt->zero ? prt->width : prt->precision + is_prefix) - len;
	if (prt->zero && prt->is_precision
			&& prt->precision + is_prefix < prt->width)
		width = prt->precision + is_prefix - len;
	if (width > 0)
	{
		aux = ft_strnew(100);
		if (is_prefix)
			aux[0] = *str;
		ft_memset(aux + is_prefix, '0', width);
		ft_strcpy(aux + is_prefix + width, str + is_prefix);
	}
	else
		aux = str;
	return (aux);
}

char	*add_width(t_printf *prt, char *str, char c)
{
	int		width;

	width = prt->width - ft_strlen(str);
	if (width > 0)
	{
		if (prt->minus)
			str = ft_strjoin(str, char_fill(width, c));
		else
			str = ft_strjoin(char_fill(width, c), str);
	}
	return (str);
}
