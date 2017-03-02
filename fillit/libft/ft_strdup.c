/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:25:39 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 16:31:05 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *d;

	d = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s1);
	return (d);
}
