/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:58:59 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 14:49:36 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		conv;
	int		is_negative;

	i = 0;
	conv = 0;
	is_negative = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	if (str[i - 1] == '-')
		is_negative = 1;
	while ((str[i] <= 57 && str[i] >= 48))
		conv = (conv * 10) + (str[i++] - 48);
	if (is_negative)
		conv *= -1;
	return (conv);
}
