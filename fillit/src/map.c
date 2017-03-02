/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:40:13 by astanciu          #+#    #+#             */
/*   Updated: 2017/01/18 17:54:07 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	display(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**fill_dots(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char**)malloc(sizeof(char*) * size);
	while (i < size)
	{
		j = 0;
		map[i] = ft_strnew(size);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
