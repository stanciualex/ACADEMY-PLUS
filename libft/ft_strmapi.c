/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:24:34 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 17:19:02 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	unsigned int	i;
	int		len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen((char *)s);
		p = (char *)malloc(len * sizeof(p) + 5);
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}
