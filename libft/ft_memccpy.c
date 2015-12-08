/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:15:37 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:16:48 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char *)dst;
	b = (char *)src;
	while (i < n && b[i])
	{
		a[i] = b[i];
		if (b[i] == c)
		{
			a[i + 1] = '\0';
			return (b);
		}
		i++;
	}
	a[i] = '\0';
	return (0);
}
