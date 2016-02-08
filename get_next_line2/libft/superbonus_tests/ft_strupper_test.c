/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:15:46 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/12 11:23:15 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char a[] = "Mesaj de TesT.";

	printf(">>> ft_strupper tests: <<<\n");
	printf("%s \n", ft_strupper(a));
	return (0);
}
