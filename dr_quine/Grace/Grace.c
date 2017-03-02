#include <stdio.h>

/*
	Acesta este un comentariu si trebuie tratat ca atare.
*/

#define FILENAME "Grace_kid.c"
#define STRING "#include <stdio.h>%c%c/*%c%cAcesta este un comentariu si trebuie tratat ca atare.%c*/%c%c#define FILENAME %cGrace_kid.c%c%c#define STRING %c%s%c%c%cvoid%cft_fprintf()%c{%c%cFILE *fp = fopen(FILENAME, %cw%c);%c%cfprintf(fp, STRING, 10, 10, 10, 9, 10, 10, 10, 34, 34, 10, 34, STRING, 34, 10, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10);%c%cfclose(fp);%c}%c%c#define FT()int main() { ft_fprintf(); return (0); }%c%cFT();"

void	ft_fprintf()
{
	FILE *fp = fopen(FILENAME, "w");
	fprintf(fp, STRING, 10, 10, 10, 9, 10, 10, 10, 34, 34, 10, 34, STRING, 34, 10, 10, 9, 10, 10, 9, 34, 34, 10, 9, 10, 9, 10, 10, 10, 10, 10);
	fclose(fp);
}

#define FT()int main() { ft_fprintf(); return (0); }

FT();