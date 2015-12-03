/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:34:42 by astanciu          #+#    #+#             */
/*   Updated: 2015/12/03 15:34:43 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    write_log(char *str);

void	create_log_file()
{
	fd = fopen("log_file.log", "a+");
	if (fd == NULL)
		write(2, "Error: Log file couldn't be created.\n", 30);
    else
    {
        write_log("=========================================\n");
        write_log("Creating the log file... Done!\n");
    }
}

void	write_log(char *str)
{
	if (fd == NULL)
		return ;
	fprintf(fd, "%s", str);
}
