#include <stdio.h>

/*
	no -42 pls
*/

void	ft_print()
{
	printf("ACADEMY+PLUS");
}

int		main()
{
	/*
		START
	*/
	char *str = "#include <stdio.h>%c%c/*%c%cno -42 pls%c*/%c%cvoid%cft_print()%c{%c%cprintf(%cACADEMY+PLUS%c);%c}%c%cint%c%cmain()%c{%c%c/*%c%c%cSTART%c%c*/%c%cchar *str = %c%s%c;%c%cprintf(str, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 9, 34, 34, 10, 10, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10);%c%creturn (0);%c}%c";
	printf(str, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 9, 34, 34, 10, 10, 10, 9, 9, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10);
	return (0);
}
