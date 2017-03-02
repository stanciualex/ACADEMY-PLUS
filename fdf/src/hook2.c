/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:51:15 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 14:58:39 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_HEIGHT_UP)
	{
		fdf->hgt += 0.06;
		draw(fdf);
	}
	if (keycode == KEY_HEIGHT_DOWN)
	{
		fdf->hgt -= 0.06;
		draw(fdf);
	}
	draw(fdf);
}

void	legend_hook(t_fdf *fdf)
{
	if (fdf->legend)
		fdf->legend = 0;
	else
		fdf->legend = 1;
	draw(fdf);
}
