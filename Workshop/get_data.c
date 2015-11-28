#include "header.h"

void get_firstname(char *buff, int k, int i)
{
	firstname[k] = buff[i];
	if (buff[i + 1] == ';')
		firstname[k + 1] = '\0';
}

void get_lastname(char *buff, int k, int i)
{
	lastname[k] = buff[i];
	if (buff[i + 1] == ';')
		lastname[k + 1] = '\0';
}

void get_email(char *buff, int k, int i)
{
	email[k] = buff[i];
	if (buff[i + 1] == ';')
		email[k + 1] = '\0';
}

void get_grade(char *buff, int k, int i)
{
	grade[k] = buff[i];
	if (buff[i + 1] == ';')
		grade[k + 1] = '\0';
}

void get_city(char *buff, int k, int i)
{
	city[k] = buff[i];
	if (buff[i + 1] == 0)
		city[k + 1] = '\0';
}
