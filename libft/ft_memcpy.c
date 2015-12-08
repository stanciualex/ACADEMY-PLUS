/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:13:35 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:14:45 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	a[i] = '\0';
	return (0);
}
