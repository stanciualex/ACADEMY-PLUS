/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:55:21 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 19:03:54 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int n, int base)
{
	char			*str;
	char			*bases;
	unsigned long	num;
	int				i;

	bases = "0123456789abcdef";
	num = n;
	str = (char*)malloc(sizeof(char) * 100);
	str[99] = '\0';
	i = 98;
	if (num == 0)
	{
		str[i] = '0';
		i--;
	}
	while (num)
	{
		str[i] = bases[num % base];
		num /= base;
		i--;
	}
	return (str + i + 1);
}
