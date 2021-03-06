/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:33:18 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 16:12:39 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < start)
		i++;
	j = 0;
	while (s[i] != '\0' && i < (start + len))
	{
		a[j] = s[i];
		i++;
		j++;
	}
	a[j] = '\0';
	return (a);
}
