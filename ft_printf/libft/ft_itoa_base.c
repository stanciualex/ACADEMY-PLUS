/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:54:52 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 19:06:19 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_string(long num, int neg, int base)
{
	int		i;
	char	*str;
	char	*bases;

	bases = "0123456789abcdef";
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
	if (neg)
	{
		str[i] = '-';
		i--;
	}
	return (str + i + 1);
}

char	*ft_itoa_base(int n, int base)
{
	int		neg;
	long	num;

	neg = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		if (base == 10)
			neg = 1;
	}
	return (create_string(num, neg, base));
}
