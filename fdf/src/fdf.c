/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:07:09 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 14:46:39 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*read_line(char *str, int size)
{
	int		i;
	t_coord	*tab;
	char	**aux;

	i = 0;
	tab = (t_coord*)malloc(sizeof(tab) * size * 2);
	aux = ft_strsplit(str, ' ');
	while (aux[i])
	{
		tab[i].x = 0;
		tab[i].y = 0;
		tab[i].z = ft_atoi(aux[i]);
		i++;
	}
	clear_mem(&aux);
	return (tab);
}

void	read_tab(t_map **map, int fd, char *filename)
{
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (!((*map)->tab = (t_coord**)malloc(sizeof(t_coord*) * (*map)->height)))
		return ;
	while (get_next_line(fd, &line))
	{
		(*map)->tab[i] = read_line(line, (*map)->width);
		i++;
	}
	close(fd);
}

void	get_map_size(t_map **map, int fd)
{
	int		lines;
	int		aux;
	int		fline;
	char	*line;

	lines = 0;
	fline = 0;
	aux = 0;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			print_error_and_exit(1);
		if (lines == 0)
			fline = count_digits(line);
		aux = count_digits(line);
		if (fline != aux)
			print_error_and_exit(2);
		lines++;
	}
	free(line);
	if (lines == 0)
		print_error_and_exit(3);
	(*map)->height = lines;
	(*map)->width = fline;
	close(fd);
}

t_map	*get_map(char *filename)
{
	int		fd;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error_and_exit(1);
	get_map_size(&map, fd);
	read_tab(&map, fd, filename);
	return (map);
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2 || argc > 3)
		print_error_and_exit(0);
	else
	{
		fdf.def_color = 0;
		if (argc == 3)
			set_def_color(argv[2], &fdf);
		fdf.map = get_map(argv[1]);
		start_mlx(&fdf);
	}
	return (0);
}
