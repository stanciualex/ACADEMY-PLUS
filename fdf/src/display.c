/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:23:47 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 15:23:49 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 5, 5, MENU_COLOR, "<LEGEND>");
	mlx_string_put(fdf->mlx, fdf->win, 5, 20, MENU_COLOR, "Rotate: UP, \
			RIGHT, DOWN, LEFT");
	mlx_string_put(fdf->mlx, fdf->win, 5, 35, MENU_COLOR, "Move: NUM8, NUM6, \
			NUM2, NUM4");
	mlx_string_put(fdf->mlx, fdf->win, 5, 50, MENU_COLOR, "Zoom: +, -");
	mlx_string_put(fdf->mlx, fdf->win, 5, 65, MENU_COLOR, "Height: H, J");
	mlx_string_put(fdf->mlx, fdf->win, 5, 80, MENU_COLOR, "Color: C");
	mlx_string_put(fdf->mlx, fdf->win, 5, 95, MENU_COLOR, "Legend ON/OFF: L");
	mlx_string_put(fdf->mlx, fdf->win, 5, 110, MENU_COLOR, "Exit: ESC or Q");
}

void	draw_line(t_points pts, t_draw draw, t_fdf *fdf)
{
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, pts.x0, pts.y0,
				fdf->colors[fdf->color_index]);
		if (pts.x0 == pts.x1 && pts.y0 == pts.y1)
			return ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			pts.x0 += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			pts.y0 += draw.sy;
		}
	}
}

void	init_draw_var(t_draw *draw, t_points pts)
{
	draw->dx = abs(pts.x1 - pts.x0);
	draw->dy = abs(pts.y1 - pts.y0);
	if (pts.x0 < pts.x1)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (pts.y0 < pts.y1)
		draw->sy = 1;
	else
		draw->sy = -1;
	if (draw->dx > draw->dy)
		draw->err = draw->dx / 2;
	else
		draw->err = -draw->dy / 2;
	draw->e2 = 0;
}

void	set_points_right(t_points *pts, t_fdf *fdf, int i, int j)
{
	pts->x0 = fdf->map->tab[i][j].x;
	pts->y0 = fdf->map->tab[i][j].y;
	pts->x1 = fdf->map->tab[i][j + 1].x;
	pts->y1 = fdf->map->tab[i][j + 1].y;
}

void	set_points_down(t_points *pts, t_fdf *fdf, int i, int j)
{
	pts->x0 = fdf->map->tab[i][j].x;
	pts->y0 = fdf->map->tab[i][j].y;
	pts->x1 = fdf->map->tab[i + 1][j].x;
	pts->y1 = fdf->map->tab[i + 1][j].y;
}
