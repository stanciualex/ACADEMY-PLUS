/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:22:44 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 16:24:01 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		p = (char *)malloc(len * sizeof(p) + 5);
		while (s[i])
		{
			p[i] = f(s[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}
