/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:03:17 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 13:52:49 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*u;
	size_t			l;

	u = b;
	l = len;
	i = 0;
	while (i < l)
	{
		u[i] = (unsigned char)c;
		i++;
	}
	return (u);
}
