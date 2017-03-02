/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:50:03 by astanciu          #+#    #+#             */
/*   Updated: 2017/01/16 18:25:02 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

typedef	struct	s_tetris
{
	char			*coord;
	char			letter;
	struct s_tetris *next;
}				t_tetris;

typedef struct	s_map
{
	int			i;
	int			j;
	int			size;
	char		**map;
}				t_map;

int				fillit(char *filename, t_map *map);
char			**read_mat(char **src, int lines, int fd, char *filename);
int				get_lines(int fd);
int				validation(char **mat, int lines);
int				check_lines(char **mat, int i, int *rel, int *pieces);
int				check_diez(char **mat, int i, int j);
t_tetris		*stock(char **mat, int lines);
char			*adjust_coord(char *src);
void			get_coord(char **mat, int i, int j, char **coord);
t_tetris		*add_list(t_tetris **lst, char *coord, char letter);
t_map			solve(t_tetris *tetriminos);
int				solve_map(t_map map, t_tetris *tetriminos);
int				verif_and_set(t_map map, t_tetris *t);
void			set_piece(t_map map, t_tetris *t, char p);
int				get_size(t_tetris *tetriminos);
void			display(char **map, int size);
char			**fill_dots(int size);

#endif
