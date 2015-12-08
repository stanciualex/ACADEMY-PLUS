/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:17:57 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:19:09 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*a;
	char	*p;
	size_t	i;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == c)
		{
			p = &a[i];
			return (p);
		}
		i++;
	}
	return (0);
}
