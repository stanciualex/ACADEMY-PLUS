/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:56:55 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/09 14:15:09 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long nr;

	nr = n;
	if (nr < 0)
	{
		ft_putchar_fd('-', fd);
		nr = -nr;
	}
	if (nr >= 10)
	{
		ft_putnbr_fd(nr / 10, fd);
		ft_putnbr_fd(nr % 10, fd);
	}
	else
	{
		ft_putchar_fd(nr + '0', fd);
	}
}
