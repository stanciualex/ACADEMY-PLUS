/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:43:15 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 16:43:48 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long n, int k)
{
	int	nr;

	nr = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		nr++;
		n /= 10;
	}
	if (k == 1)
		return (nr + 1);
	return (nr);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		nr;
	int		k;
	long	z;

	k = 0;
	z = n;
	if (z < 0)
	{
		z = -z;
		k = 1;
	}
	nr = numlen(z, k);
	str = (char*)malloc((nr + 1 + k) * sizeof(char));
	str[nr] = '\0';
	if (k == 1)
		str[0] = '-';
	nr--;
	while (nr >= k)
	{
		str[nr] = z % 10 + '0';
		z /= 10;
		nr--;
	}
	return (str);
}
