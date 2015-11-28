#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 255
#define NAME_SIZE 20
#define EMAIL_SIZE 20
#define GRADE_SIZE 5
#define CITY_SIZE 10

char firstname[NAME_SIZE], lastname[NAME_SIZE], email[EMAIL_SIZE], grade[GRADE_SIZE], city[CITY_SIZE];
FILE *fd;

int check_file_open(FILE *fp);
void get_firstname(char *buff, int k, int i);
void get_lastname(char *buff, int k, int i);
void get_email(char *buff, int k, int i);
void get_grade(char *buff, int k, int i);
void get_city(char *buff, int k, int i);
void create_log_file();
void write_log(char *str);
void check_line(char *buff);
void stock_data(char *buff);
void check_firstname();
void check_lastname();
void check_email();
void check_grade();
void check_city();
void check_get(int j);
void clear_str(char *str);
void clear_data();
void print_students();
char *ft_itoa(int n);
int ft_isalpha(char c);

#endif // HEADER_H
