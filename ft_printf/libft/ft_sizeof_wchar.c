/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:30:35 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/13 17:30:44 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeof_wchar(wchar_t wc)
{
	if (wc < 0x7F)
		return (1);
	else if (wc < 0x7FF)
		return (2);
	else if (wc < 0xFFFF)
		return (3);
	return (4);
}
