/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:39:01 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 14:52:46 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	str = ft_strdup(str);
	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}
