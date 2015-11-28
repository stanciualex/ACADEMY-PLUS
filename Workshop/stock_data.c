#include "header.h"

void	stock_data(char *buff)
{
	int		i, j, k;
	i = 0;
	j = 0;
	k = 0;
	while (*(buff + i) != 0)
	{
		if (buff[i] == ';')
		{
			check_get(j);
			j++;
			k = 0;
		}
		else
		{
			if (j == 0)
				get_firstname(buff, k, i);
			if (j == 1)
				get_lastname(buff, k, i);
			if (j == 2)
				get_email(buff, k, i);
			if (j == 3)
				get_grade(buff, k, i);
			if (j == 4)
				get_city(buff, k, i);
			k++;
		}
		i++;
	}
	check_get(4);
}
