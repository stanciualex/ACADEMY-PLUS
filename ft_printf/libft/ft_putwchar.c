/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:23:25 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 17:23:37 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_bits(unsigned int nbr)
{
	int i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

void			ft_putwchar(wchar_t wchar)
{
	unsigned int	ch;
	int				n;

	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7)
	{
		if (n > 11)
		{
			if (n > 16)
			{
				ft_putchar(((ch >> 18) & 7) | 240);
				ft_putchar(((ch >> 12) & 63) | 128);
			}
			else
				ft_putchar(((ch >> 12) & 15) | 224);
			ft_putchar(((ch >> 6) & 63) | 128);
		}
		else
			ft_putchar(((ch >> 6) & 31) | 192);
		ft_putchar((ch & 63) | 128);
	}
	else
		ft_putchar(ch);
}
