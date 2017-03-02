/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:43:08 by astanciu          #+#    #+#             */
/*   Updated: 2017/01/14 19:57:59 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		get_size(t_tetris *tetriminos)
{
	int		count;
	int		size;

	count = 0;
	size = 1;
	while (tetriminos)
	{
		count++;
		tetriminos = tetriminos->next;
	}
	while (size * size < count * 4)
		size++;
	return (size);
}

void	set_piece(t_map map, t_tetris *t, char p)
{
	int		index;
	int		x;
	int		y;

	index = 0;
	while (index < 8)
	{
		x = map.i + (t->coord[index] - '0');
		y = map.j + (t->coord[index + 1] - '0');
		map.map[x][y] = p;
		index += 2;
	}
}

int		verif_and_set(t_map map, t_tetris *t)
{
	int		index;
	int		x;
	int		y;

	index = 0;
	while (index < 8)
	{
		x = map.i + (t->coord[index] - '0');
		y = map.j + (t->coord[index + 1] - '0');
		if (x >= map.size || y >= map.size || x < 0 || y < 0 ||
				ft_isalpha(map.map[x][y]))
			return (0);
		index += 2;
	}
	set_piece(map, t, t->letter);
	return (1);
}

int		solve_map(t_map map, t_tetris *tetriminos)
{
	if (tetriminos == NULL)
		return (1);
	map.i = 0;
	while (map.i < map.size)
	{
		map.j = 0;
		while (map.j < map.size)
		{
			if (verif_and_set(map, tetriminos))
			{
				if (solve_map(map, tetriminos->next))
					return (1);
				else
					set_piece(map, tetriminos, '.');
			}
			map.j++;
		}
		map.i++;
	}
	return (0);
}

t_map	solve(t_tetris *tetriminos)
{
	t_map	map;

	map.size = get_size(tetriminos);
	map.map = fill_dots(map.size);
	while (!solve_map(map, tetriminos))
	{
		map.size++;
		map.map = fill_dots(map.size);
	}
	return (map);
}
