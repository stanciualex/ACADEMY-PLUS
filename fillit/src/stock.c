/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:39:52 by astanciu          #+#    #+#             */
/*   Updated: 2017/01/14 19:58:10 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris		*add_list(t_tetris **lst, char *coord, char letter)
{
	t_tetris	*new;
	t_tetris	*start;

	new = (t_tetris*)malloc(sizeof(*new));
	new->coord = (char*)malloc(sizeof(char) * 8);
	ft_memcpy(new->coord, coord, 8);
	new->letter = letter;
	new->next = NULL;
	start = *lst;
	if (letter == 'A')
		*lst = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
	return (start);
}

void			get_coord(char **mat, int i, int j, char **coord)
{
	mat[i][j] = '.';
	ft_strcat(*coord, ft_itoa(i - 5 * (i / 5)));
	ft_strcat(*coord, ft_itoa(j));
	if (i > 0 && mat[i - 1][j] == '#')
		get_coord(mat, i - 1, j, coord);
	if (j < 3 && mat[i][j + 1] == '#')
		get_coord(mat, i, j + 1, coord);
	if (i < 3 && mat[i + 1][j] == '#')
		get_coord(mat, i + 1, j, coord);
	if (j > 0 && mat[i][j - 1] == '#')
		get_coord(mat, i, j - 1, coord);
}

char			*adjust_coord(char *src)
{
	int		i;
	char	*str;
	char	min_x;
	char	min_y;

	str = src;
	i = 0;
	min_x = '4';
	min_y = '4';
	while (i < 8)
	{
		if (str[i] < min_x)
			min_x = str[i];
		if (str[i + 1] < min_y)
			min_y = str[i + 1];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		str[i] -= (min_x - '0');
		str[i + 1] -= (min_y - '0');
		i += 2;
	}
	return (str);
}

t_tetris		*stock(char **mat, int lines)
{
	int			i;
	int			j;
	char		*coord;
	t_tetris	*tetriminos;

	i = -1;
	coord = (char *)malloc(sizeof(char) * 8);
	while (++i < lines)
	{
		if (i % 5 != 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (mat[i][j] == '#')
					get_coord(mat, i, j, &coord);
			}
		}
		if (i % 5 == 3)
		{
			add_list(&tetriminos, adjust_coord(coord), (i / 5) + 'A');
			ft_strclr(coord);
		}
	}
	return (tetriminos);
}
