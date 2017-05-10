/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:40:00 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 18:53:32 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *wstr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (wstr[i])
	{
		count += ft_sizeof_wchar(wstr[i]);
		i++;
	}
	return (count);
}
