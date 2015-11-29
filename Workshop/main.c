#include "header.h"

int main()
{
	FILE *fp;
	char buff[BUFF_SIZE];
	int i;

	i = 1;
	create_log_file();
	write_log("Opening the log file... Done!\n");
	fp = fopen("students.csv", "r");
	if (!check_file_open(fp))
		return 0;
	while (fscanf(fp, "%s", buff) > 0)
	{
            write_log("Checking the line #");
            write_log(ft_itoa(i));
            write_log("... Done!\n");
            check_line(buff);
            write_log("Stocking student data... Done!\n");
            stock_data(buff);
            write_log("Checking and if it's necesarry, printing... Done!\n");
            print_students();
            clear_data();
			i++;
    }
    write_log("The program execution has just ended.\n");
    write_log("=========================================\n\n\n\n\n");
    fclose(fd);
	return 0;
}
