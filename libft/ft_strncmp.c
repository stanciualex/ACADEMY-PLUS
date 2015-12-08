/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:57:21 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:57:57 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	while ((s1[index] || s2[index]) && (index < n))
	{
		if (s1[index] < s2[index])
			return (s1[index] - s2[index]);
		if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}
