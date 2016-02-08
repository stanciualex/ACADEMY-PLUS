/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:34:39 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:36:16 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		dest_size;

	i = 0;
	dest_size = 0;
	while (s1[dest_size])
		dest_size++;
	while (s2[i])
	{
		s1[dest_size] = s2[i];
		dest_size++;
		i++;
	}
	s1[dest_size] = '\0';
	return (s1);
}
