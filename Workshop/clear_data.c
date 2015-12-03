/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:32:38 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/03 15:32:44 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void clear_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

void clear_data()
{
	clear_str(firstname);
	clear_str(lastname);
	clear_str(email);
	clear_str(grade);
	clear_str(city);
}
