/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:43:21 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/12 11:21:08 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char c1;
	char c2;
	char c3;
	char c4;
	char c5;

	c1 = 'a';
	c2 = 'A';
	c3 = '#';
	c4 = '8';
	c5 = 'x';
	printf(">>> ft_islower tests: <<<\n");
	printf("%c - %d \n", c1, ft_islower(c1));
	printf("%c - %d \n", c2, ft_islower(c2));
	printf("%c - %d \n", c3, ft_islower(c3));
	printf("%c - %d \n", c4, ft_islower(c4));
	printf("%c - %d \n", c5, ft_islower(c5));
	return (0);
}
