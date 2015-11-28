#include "header.h"

const char cities[][20] = {"Alba", "Arad", "Arges", "Bacau", "Bihor"
"Bistrita-Nasaud", "Botosani", "Brasov", "Buzau", "Caras-Severin",
"Calarasi", "Cluj", "Constanta", "Covasna", "Dambovita", "Dolj",
"Galati", "Giurgiu", "Gorj", "Harghita", "Hunedoara", "Ialomita",
"Iasi", "Ilfov", "Maramures", "Mehedinti", "Mures", "Neamt", "Olt",
"Prahova", "Satu-Mare", "Salaj", "Sibiu", "Suceava", "Teleorman",
"Timis", "Tulcea", "Vaslui", "Valcea", "Vrancea"};
const int NUMBER_OF_CITIES = 40;

int check_file_open(FILE *fp)
{
	if (!fp)
	{
		write_log("Error: No file was opened.\n");
		return 0;
	}
	return 1;
}

void check_line(char *buff)
{
    int i;
    int nr;

    i = 0;
    nr = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (buff[i] == ';' || buff[i] == '\0')
			nr++;
		i++;
	}
	if (nr < 4)
		write_log("Error: Too few data on line.\n");
	if (nr > 4)
		write_log("Error: Too many data on line.\n");
}

void check_firstname()
{
    int i;

	if (*firstname == 0)
	{
		write_log("Error: The first name does not exist.\n");
		return ;
	}
	i = 0;
	if (ft_isalpha(firstname[0]) && (firstname[0] < 'A' || firstname[0] > 'Z'))
    {
        write_log("Error: Invalid first name. The first letter must be an uppercase.\n");
        return ;
    }
	while (firstname[i])
	{
	    if (!ft_isalpha(firstname[i]))
        {
            write_log("Error: The first name contain invalid characters.\n");
            return ;
        }
		i++;
	}
}

void check_lastname()
{
    int i;

	if (*lastname == 0)
	{
		write_log("Error: The last name does not exist.\n");
		return ;
	}
	i = 0;
	if (ft_isalpha(lastname[0]) && (lastname[0] < 'A' || lastname[0] > 'Z'))
    {
        write_log("Error: Invalid last name. The first letter must be an uppercase.\n");
        return ;
    }
	while (lastname[i])
	{
	    if (!ft_isalpha(lastname[i]))
        {
            write_log("Error: The last name contain invalid characters.\n");
            return ;
        }
		i++;
	}
}

void check_email()
{
    char *ptr;

    if (*email == 0)
    {
        write_log("Error: No email entered.\n");
        return ;
    }
    ptr = NULL;
    if (!(ptr = strchr(email, '@')) || !strchr(ptr, '.'))
    {
        write_log("Error: Invalid email.\n");
        return ;
    }
}

void check_grade()
{
    int i;
    int count_dots;

    if (*grade == 0)
    {
        write_log("Error: No grade entered.\n");
        return ;
    }
    i = 0;
    count_dots = 0;
    while (grade[i])
    {
        if (!strchr(".0123456789", grade[i]))
        {
            write_log("Error: Invalid grade.\n");
            return ;
        }
        if (grade[i] == '.')
            count_dots++;
        i++;
    }
    if (count_dots != 1)
    {
        write_log("Error: Invalid grade.\n");
        return ;
    }
}

void check_city()
{
    int i;
    int found;

    if (*city == 0)
    {
        write_log("Error: No city entered.\n");
        return ;
    }
    if (ft_isalpha(city[0]) && (city[0] < 'A' || city[0] > 'Z'))
    {
        write_log("Error: Invalid city. The first letter must be an uppercase.\n");
        return ;
    }
    i = 0;
    found = 0;
    while (i < NUMBER_OF_CITIES)
    {
        if (strcasecmp(cities[i], city) == 0)
        {
            found = 1;
            break ;
        }
        i++;
    }
    if (found != 1)
    {
        write_log("Error: Invalid city.\n");
        return ;
    }
}

void	check_get(int j)
{
	if (j == 0)
		check_firstname();
	if (j == 1)
		check_lastname();
	if (j == 2)
		check_email();
	if (j == 3)
		check_grade();
	if (j == 4)
		check_city();
}
