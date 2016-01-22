/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:00:16 by astanciu          #+#    #+#             */
/*   Updated: 2016/01/22 16:29:15 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage()
{
	ft_putstr("usage: ./fillit [filne_name]\n");
}

void	error()
{
	ft_putstr("error\n");
}

int		validations(int argc, char *filename)
{
	int		fd;
	if (argc != 2)
	{
		usage();
		return (0);
	}
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		error();
		return (0);
	}
	return (fd);
}
