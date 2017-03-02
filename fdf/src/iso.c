/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 17:05:45 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 17:12:01 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_conversion(t_fdf *fdf)
{
	double		sin_angle;
	double		cos_angle;
	double		spacing;
	int			i;
	int			j;

	sin_angle = sin(fdf->sin * M_PI / 180);
	cos_angle = cos(fdf->cos * M_PI / 180);
	spacing = fdf->zoom * (WIDTH / (fdf->map->height * 0.5 + fdf->map->width
		* 0.86));
	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
		{
			fdf->map->tab[i][j].x = (i - fdf->map->height / 2) * spacing
				* -cos_angle + (j - fdf->map->width / 2) * spacing
				* cos_angle + WIDTH / 2 + fdf->xm;
			fdf->map->tab[i][j].y = (i - fdf->map->height / 2) * spacing
				* sin_angle - (j - fdf->map->width / 2) * spacing * -sin_angle
				- fdf->map->tab[i][j].z * fdf->hgt * spacing
				+ HEIGHT / 2 + fdf->ym;
		}
	}
}
