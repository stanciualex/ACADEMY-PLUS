/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:13:04 by astanciu          #+#    #+#             */
/*   Updated: 2015/11/25 16:48:44 by astanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 255

char firstname[20], lastname[20], email[20], grade[5], city[10];

int open_file_check(FILE *fp)
{
	if (!fp)
	{
		write(1, "The file couldn't be opened.\n", 29);
		return 0;
	}
	return 1;
}

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
	if (buff[i + 1] == ';')
		city[k + 1] = '\0';
}

void print_students()
{
	if (strcmp(city, "Cluj") == 0 && atof(grade) > 8.00)
		printf("%s %s\n", firstname, lastname);
}

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

int main()
{
	FILE *fp;
	char buff[BUFF_SIZE];
	int i, j, k;

	i = 0;
	j = 0;
	k = 0;
	fp = fopen("students.csv", "r");
	if (!open_file_check(fp))
		return 0;
	while (fscanf(fp, "%s", buff) > 0)
	{
		i = 0;
		j = 0;
		k = 0;
		while (*(buff + i) != 0)
		{
			if (buff[i] == ';')
			{
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
		print_students();
		clear_data();
	}
	return 0;
}

