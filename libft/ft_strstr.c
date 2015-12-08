/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:49:15 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:51:25 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		z;
	int		to_find_size;

	i = 0;
	z = 0;
	to_find_size = 0;
	while (s2[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return (s1);
	while (s1[i])
	{
		while (s2[z] == s1[i + z])
		{
			if (z == to_find_size - 1)
				return (s1 + i);
			z++;
		}
		z = 0;
		i++;
	}
	return (0);
}
