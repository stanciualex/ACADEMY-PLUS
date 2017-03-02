/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:10:58 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 14:39:51 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *aux;

	aux = (void *)malloc(size);
	if (aux == NULL)
		return (NULL);
	aux = ft_memset(aux, 0, size);
	return (aux);
}
