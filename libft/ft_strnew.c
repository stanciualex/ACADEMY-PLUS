/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:13:17 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 16:14:31 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	int		i;

	if (size <= 0)
		return (NULL);
	i = 0;
	a = (char*)malloc(sizeof(size) + 1);
	while (i < sizeof(size) + 1)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
