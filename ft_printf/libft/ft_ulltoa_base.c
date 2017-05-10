/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:56:17 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 19:05:47 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, int base)
{
	char				*str;
	char				*bases;
	unsigned long long	num;
	int					i;

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
