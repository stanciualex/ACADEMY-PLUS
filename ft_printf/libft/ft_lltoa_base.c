/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:55:51 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:56:04 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_string(unsigned long long num, int neg, int base)
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

char	*ft_lltoa_base(long long n, int base)
{
	int					neg;
	unsigned long long	num;

	neg = 0;
	if (n < 0)
	{
		num = -n;
		if (base == 10)
			neg = 1;
	}
	else
		num = n;
	return (create_string(num, neg, base));
}
