/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:13:17 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 13:34:09 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	if (size <= 0)
		return (NULL);
	i = 0;
	a = (char*)malloc(size);
	if (a == NULL)
		return (NULL);
	while (i < size + 1)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
