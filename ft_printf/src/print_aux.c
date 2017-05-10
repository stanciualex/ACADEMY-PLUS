/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:51:12 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:48:35 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		nbr_bits(unsigned int nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

void	ft_putnwstr(wchar_t *wstr, int n)
{
	int		i;

	i = 0;
	while (wstr[i] && i < n)
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}

void	ft_putnchar(char c, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar(c);
		i++;
	}
}
