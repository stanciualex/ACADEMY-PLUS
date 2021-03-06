/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:43:09 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 13:37:05 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*p;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			p = (char *)&s[i];
			return (p);
		}
		i++;
	}
	if (c == s[i])
	{
		p = (char *)&s[i];
		return (p);
	}
	return (NULL);
}
