/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:48:37 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/12 11:23:30 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	int a;
	int b;
	int x;
	int y;

	a = 42;
	b = 8;
	x = 100;
	y = -15;
	printf(">>> ft_swap tests: <<<\n");
	printf("a = %d b = %d \n", a, b);
	ft_swap(&a, &b);
	printf("a = %d b = %d \n", a, b);
	printf("x = %d y = %d \n", x, y);
	ft_swap(&x, &y);
	printf("x = %d y = %d \n", x, y);
	return (0);
}
