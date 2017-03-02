/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:58:07 by astanciu          #+#    #+#             */
/*   Updated: 2017/01/18 17:48:07 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_diez(char **mat, int i, int j)
{
	int		sum;

	sum = 0;
	if (i - 5 * (i / 5) > 0 && mat[i - 1][j] == '#')
		sum++;
	if (j > 0 && mat[i][j - 1] == '#')
		sum++;
	if (i - 5 * (i / 5) < 3 && mat[i + 1][j] == '#')
		sum++;
	if (j < 3 && mat[i][j + 1] == '#')
		sum++;
	return (sum);
}

int		check_lines(char **mat, int i, int *rel, int *pieces)
{
	int		j;

	j = 0;
	if (i - 5 * (i / 5) == 0)
	{
		*rel = 0;
		*pieces = 0;
	}
	while (j < 4)
	{
		if (mat[i][j] != '.' && mat[i][j] != '#' && mat[i][j] != '\0')
			return (0);
		if (mat[i][j] == '#')
		{
			*rel += check_diez(mat, i, j);
			*(pieces) += 1;
		}
		j++;
	}
	return (1);
}

int		validation(char **mat, int lines)
{
	int		i;
	int		rel;
	int		pieces;

	i = 0;
	if (lines > 129 || (lines % 10 != 4 && lines % 10 != 9))
		return (0);
	while (i < lines)
	{
		if (check_lines(mat, i, &rel, &pieces) == 0)
			return (0);
		if (i - 5 * (i / 5) == 3 && ((rel != 6 && rel != 8) || pieces != 4))
			return (0);
		if (i % 5 == 4)
		{
			if (ft_strlen(mat[i]) > 0)
				return (0);
			rel = 0;
			pieces = 0;
		}
		else if (ft_strlen(mat[i]) != 4)
			return (0);
		i++;
	}
	return (1);
}
