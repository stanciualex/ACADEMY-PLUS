/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:14:46 by astanciu          #+#    #+#             */
/*   Updated: 2017/03/15 17:49:18 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	verify_color2(t_printf *prt, char *color)
{
	if (ft_strcmp(color, "magenta") == 0)
	{
		ft_putstr(COLOR_MAGENTA);
		prt->str += ft_strlen(color) + 1;
	}
	else if (ft_strcmp(color, "cyan") == 0)
	{
		ft_putstr(COLOR_CYAN);
		prt->str += ft_strlen(color) + 1;
	}
	else if (ft_strcmp(color, "eoc") == 0)
	{
		ft_putstr(COLOR_RESET);
		prt->str += ft_strlen(color) + 1;
	}
	else
		prt->str--;
}

void	verify_color(t_printf *prt, char *color)
{
	if (ft_strcmp(color, "red") == 0)
	{
		ft_putstr(COLOR_RED);
		prt->str += ft_strlen(color) + 1;
	}
	else if (ft_strcmp(color, "green") == 0)
	{
		ft_putstr(COLOR_GREEN);
		prt->str += ft_strlen(color) + 1;
	}
	else if (ft_strcmp(color, "yellow") == 0)
	{
		ft_putstr(COLOR_YELLOW);
		prt->str += ft_strlen(color) + 1;
	}
	else if (ft_strcmp(color, "blue") == 0)
	{
		ft_putstr(COLOR_BLUE);
		prt->str += ft_strlen(color) + 1;
	}
	else
		verify_color2(prt, color);
}

void	check_color(t_printf *prt)
{
	char	*aux;
	char	*color;

	prt->str++;
	aux = (char*)malloc(sizeof(char) * 100);
	color = (char*)malloc(sizeof(char) * 100);
	aux = ft_strchr(prt->str, '}');
	if (!aux)
		return ;
	ft_strncpy(color, prt->str, ft_strlen(prt->str) - ft_strlen(aux));
	verify_color(prt, color);
}
