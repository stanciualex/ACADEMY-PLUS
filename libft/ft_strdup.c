/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:25:39 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:27:44 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *a;
	char *q;
	char *p;

	p = s1;
	a = (char*)malloc(sizeof(char) + sizeof(s1) + 1);
	q = a;
	while (*p)
	{
		*a = *p;
		a++;
		p++;
	}
	*a = '\0';
	free(s1);
	return (q);
}
