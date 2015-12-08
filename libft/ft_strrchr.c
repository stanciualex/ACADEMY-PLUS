/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:45:46 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/08 15:48:37 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*p;

	i = ft_strlen(s);
	if (c == '\0')
	{
		p = (char *)&s[i - 1];
		return (p);
	}
	while (i >= 0)
	{
		if (s[i] == c)
		{
			p = (char *)&s[i];
			return (p);
		}
		i--;
	}
	return (0);
}
