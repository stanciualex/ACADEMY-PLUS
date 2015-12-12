/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:47:15 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/12 11:21:55 by astanciu         ###   ########.fr       */
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
	c5 = 'X';
	printf(">>> ft_isupper tests: <<<\n");
	printf("%c - %d \n", c1, ft_isupper(c1));
	printf("%c - %d \n", c2, ft_isupper(c2));
	printf("%c - %d \n", c3, ft_isupper(c3));
	printf("%c - %d \n", c4, ft_isupper(c4));
	printf("%c - %d \n", c5, ft_isupper(c5));
	return (0);
}
