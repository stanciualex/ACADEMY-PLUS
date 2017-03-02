/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:59:11 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 14:44:45 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_and_draw(t_fdf *fdf, int i, int j)
{
	t_points	pts;
	t_draw		draw;

	if (j < fdf->map->width - 1)
	{
		set_points_right(&pts, fdf, i, j);
		init_draw_var(&draw, pts);
		draw_line(pts, draw, fdf);
	}
	if (i < fdf->map->height - 1)
	{
		set_points_down(&pts, fdf, i, j);
		init_draw_var(&draw, pts);
		draw_line(pts, draw, fdf);
	}
}

int		draw(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	mlx_clear_window(fdf->mlx, fdf->win);
	iso_conversion(fdf);
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			init_and_draw(fdf, i, j);
			j++;
		}
		i++;
	}
	if (fdf->legend)
		display_menu(fdf);
	return (0);
}

void	init_colors(t_fdf *fdf)
{
	if (fdf->def_color)
		fdf->colors[0] = fdf->def_color;
	else
		fdf->colors[0] = WHITE;
	fdf->colors[1] = RED;
	fdf->colors[2] = YELLOW;
	fdf->colors[3] = BLUE;
	fdf->colors[4] = AQUA_BLUE;
	fdf->colors[5] = GREEN;
	fdf->colors[6] = LIME_GREEN;
	fdf->colors[7] = PINK;
	fdf->colors[8] = PURPLE;
	fdf->colors[9] = MAROON;
	fdf->colors[10] = OLIVE;
	fdf->colors[11] = NAVY;
	fdf->colors[12] = GRAY;
	fdf->colors[13] = TEAL;
	fdf->colors[14] = ORANGE;
	fdf->colors[15] = GOLD;
}

void	init(t_fdf *fdf)
{
	fdf->zoom = 0.75;
	fdf->hgt = 0.12;
	fdf->sin = 40;
	fdf->cos = 30;
	fdf->xm = 0;
	fdf->ym = 0;
	fdf->color_index = 0;
	fdf->legend = 1;
	init_colors(fdf);
}

void	start_mlx(t_fdf *fdf)
{
	init(fdf);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "42 fdf");
	mlx_expose_hook(fdf->win, draw, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}
