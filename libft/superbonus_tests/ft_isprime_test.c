/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:23:25 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/12 11:22:06 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	printf(">>> ft_isprime tests: <<<\n");
	printf("%s %d \n", "5 --- ", ft_isprime(5));
	printf("%s %d \n", "10 -- ", ft_isprime(10));
	printf("%s %d \n", "13 -- ", ft_isprime(13));
	printf("%s %d \n", "100 - ", ft_isprime(100));
	printf("%s %d \n", "-5: - ", ft_isprime(-5));
	printf("%s %d \n", "42 -- ", ft_isprime(42));
	printf("%s %d \n", "31 -- ", ft_isprime(31));
	return (0);
}
