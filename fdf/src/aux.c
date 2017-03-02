/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:56:50 by astanciu          #+#    #+#             */
/*   Updated: 2017/02/07 15:00:38 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error_and_exit(int error)
{
	char	**msg;

	msg = (char**)malloc(sizeof(char*) * 5);
	msg[0] = "Usage: ./fdf [filename] [optional: color]\nColor format: \
0xFFFFFF";
	msg[1] = "Error: no file opened";
	msg[2] = "Error: different number of values on lines";
	msg[3] = "Error: the file is empty";
	msg[4] = "Error: invalid color";
	ft_putstr(msg[error]);
	ft_putchar('\n');
	exit(0);
}

void	clear_mem(char ***src)
{
	int		i;

	i = 0;
	while (*src[i])
	{
		free(*src[i]);
		i++;
	}
}

int		count_digits(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (count);
}

int		gv(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c == 'A' || c == 'a')
		return (10);
	if (c == 'B' || c == 'b')
		return (11);
	if (c == 'C' || c == 'c')
		return (12);
	if (c == 'D' || c == 'd')
		return (13);
	if (c == 'E' || c == 'e')
		return (14);
	if (c == 'F' || c == 'f')
		return (15);
	print_error_and_exit(4);
	return (0);
}

void	set_def_color(char *str, t_fdf *fdf)
{
	int		i;
	int		p;
	int		n;

	if (*str != '0' || *(str + 1) != 'x')
		print_error_and_exit(4);
	if (ft_strlen(str) > 8)
		print_error_and_exit(4);
	str += 2;
	i = ft_strlen(str) - 1;
	n = 0;
	p = 1;
	while (i >= 0)
	{
		n += gv(str[i]) * p;
		p *= 16;
		i--;
	}
	fdf->def_color = n;
}
