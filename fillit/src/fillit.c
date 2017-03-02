/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:49:52 by astanciu          #+#    #+#             */
/*   Updated: 2017/01/14 19:57:38 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		get_lines(int fd)
{
	int		lines;
	char	*line;

	lines = 0;
	while (get_next_line(fd, &line))
		lines++;
	close(fd);
	return (lines);
}

char	**read_mat(char **src, int lines, int fd, char *filename)
{
	int		i;
	char	*line;
	char	**mat;

	mat = src;
	i = 0;
	fd = open(filename, O_RDONLY);
	mat = (char**)malloc(sizeof(char *) * lines + 1);
	while (get_next_line(fd, &line))
	{
		mat[i] = (char *)malloc(sizeof(char) * 5);
		mat[i] = ft_strdup(line);
		i++;
	}
	close(fd);
	return (mat);
}

int		fillit(char *filename, t_map *map)
{
	int			fd;
	int			lines;
	char		**mat;
	t_tetris	*tetriminos;

	mat = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	lines = get_lines(fd);
	mat = read_mat(mat, lines, fd, filename);
	if (!validation(mat, lines))
		return (0);
	tetriminos = stock(mat, lines);
	*map = solve(tetriminos);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit [filename]\n");
		return (0);
	}
	if (!fillit(argv[1], &map))
	{
		ft_putstr("error\n");
		return (0);
	}
	display(map.map, map.size);
	return (0);
}
