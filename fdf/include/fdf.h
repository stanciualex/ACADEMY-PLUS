/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:07:14 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 15:56:04 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_DOWN_ARROW 125
# define KEY_UP_ARROW 126
# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78
# define KEY_COLOR 8
# define KEY_HEIGHT_UP 4
# define KEY_HEIGHT_DOWN 38
# define KEY_MOVE_UP 91
# define KEY_MOVE_DOWN 84
# define KEY_MOVE_RIGHT 88
# define KEY_MOVE_LEFT 86
# define KEY_LEGEND 37

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define AQUA_BLUE 0x00FFFF
# define GREEN 0x33CC33
# define LIME_GREEN 0x00FF00
# define PINK 0xFF3399
# define PURPLE 0x9900FF
# define MAROON 0x800000
# define OLIVE 0x808000
# define NAVY 0x9966FF
# define GRAY 0x808080
# define TEAL 0x008080
# define ORANGE 0xFFA500
# define GOLD 0xFFD700

# define MENU_COLOR 0x98f442

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
}				t_coord;

typedef struct	s_points
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_points;

typedef struct	s_draw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}				t_draw;

typedef struct	s_map
{
	t_coord	**tab;
	int		width;
	int		height;
}				t_map;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_map	*map;
	double	zoom;
	double	hgt;
	int		sin;
	int		cos;
	int		xm;
	int		ym;
	int		colors[16];
	int		color_index;
	int		def_color;
	int		legend;
}				t_fdf;

/*
** 				fdf.c
*/
t_coord			*read_line(char *str, int size);
void			read_tab(t_map **map, int fd, char *filename);
void			get_map_size(t_map **map, int fd);
t_map			*get_map(char *filename);

/*
** 				mlx.c
*/
void			init_and_draw(t_fdf *fdf, int i, int j);
int				draw(t_fdf *fdf);
void			init_colors(t_fdf *fdf);
void			init(t_fdf *fdf);
void			start_mlx(t_fdf *fdf);

/*
** 				display.c
*/
void			display_menu(t_fdf *fdf);
void			draw_line(t_points pts, t_draw draw, t_fdf *fdf);
void			init_draw_var(t_draw *draw, t_points pts);
void			set_points_right(t_points *pts, t_fdf *fdf, int i, int j);
void			set_points_down(t_points *pts, t_fdf *fdf, int i, int j);

/*
** 				iso.c
*/
void			iso_conversion(t_fdf *fdf);

/*
** 				hook.c
*/
void			rotate_hook(int keycode, t_fdf *fdf);
void			zoom_hook(int keycode, t_fdf *fdf);
void			move_hook(int keycode, t_fdf *fdf);
void			color_hook(t_fdf *fdf);
int				key_hook(int keycode, t_fdf *fdf);

/*
** 				hook2.c
*/
void			height_hook(int keycode, t_fdf *fdf);
void			legend_hook(t_fdf *fdf);

/*
** 				aux.c
*/
void			print_error_and_exit(int error);
void			clear_mem(char ***src);
int				count_digits(char *str);
int				gv(char c);
void			set_def_color(char *str, t_fdf *fdf);

#endif
