/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:29:40 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:33:42 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	index;

	index = 0;
	while (src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = src[index];
	return (dst);
}
