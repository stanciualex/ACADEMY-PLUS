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
