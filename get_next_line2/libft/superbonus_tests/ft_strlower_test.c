/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:55:03 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/12 11:24:00 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char a[] = "MESAJ de TesT.";

	printf(">>> ft_strlower tests: <<<\n");
	printf("%s \n", ft_strlower(a));
	return (0);
}
