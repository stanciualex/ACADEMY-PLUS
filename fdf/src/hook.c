/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:16:58 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 14:40:28 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP_ARROW)
		fdf->sin += 5;
	if (keycode == KEY_DOWN_ARROW)
		fdf->sin -= 5;
	if (keycode == KEY_LEFT_ARROW)
		fdf->cos -= 5;
	if (keycode == KEY_RIGHT_ARROW)
		fdf->cos += 5;
	draw(fdf);
}

void	zoom_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ZOOM_IN)
	{
		if (fdf->zoom < 3)
			fdf->zoom += 0.1;
	}
	if (keycode == KEY_ZOOM_OUT)
	{
		if (fdf->zoom > 0.1)
			fdf->zoom -= 0.1;
	}
	draw(fdf);
}

void	move_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_MOVE_RIGHT)
		fdf->xm += 50;
	if (keycode == KEY_MOVE_LEFT)
		fdf->xm -= 50;
	if (keycode == KEY_MOVE_UP)
		fdf->ym -= 50;
	if (keycode == KEY_MOVE_DOWN)
		fdf->ym += 50;
	draw(fdf);
}

void	color_hook(t_fdf *fdf)
{
	if (fdf->color_index == 15)
		fdf->color_index = 0;
	else
		fdf->color_index++;
	draw(fdf);
}

int		key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit(0);
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW ||
		keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW)
		rotate_hook(keycode, fdf);
	if (keycode == KEY_COLOR)
		color_hook(fdf);
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		zoom_hook(keycode, fdf);
	if (keycode == KEY_MOVE_RIGHT || keycode == KEY_MOVE_LEFT ||
		keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN)
		move_hook(keycode, fdf);
	if (keycode == KEY_HEIGHT_UP || keycode == KEY_HEIGHT_DOWN)
		height_hook(keycode, fdf);
	if (keycode == KEY_LEGEND)
		legend_hook(fdf);
	return (0);
}
