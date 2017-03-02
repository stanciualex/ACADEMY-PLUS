#include <stdio.h>
#include <stdlib.h>
#define EXEC "Sully"

int i = 5;

int main()
{
	if (i > 0)
	{
		FILE	*fp;
		char	*filename;
		char	*cmd;
		char	*str = "#include <stdio.h>%c#include <stdlib.h>%c#define EXEC %cSully%c%c%cint i = %d;%c%cint main()%c{%c%cif (i > 0)%c%c{%c%c%cFILE%c*fp;%c%c%cchar%c*filename;%c%c%cchar%c*cmd;%c%c%cchar%c*str = %c%s%c;%c%c%cfilename = (char *)malloc(sizeof(char) * 10);%c%c%ccmd = (char *)malloc(sizeof(char) * 150);%c%c%csprintf(filename, %cSully_%cd.c%c, i - 1);%c%c%cfp = fopen(filename, %cw%c);%c%c%cfprintf(fp, str, 10, 10, 34, 34, 10, 10, i - 1, 10, 10, 10, 10, 9, 10, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 34, str, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 34, 37, 37, 37, 34, 10, 9, 9, 9, 10, 9, 9, 10, 9, 10, 9, 10);%c%c%cfclose(fp);%c%c%cif (i - 1 > 0)%c%c%c{%c%c%c%csprintf(cmd, %cclang -Wall -Wextra -Werror -o %cs %cs; ./%cs%c, EXEC, filename, EXEC);%c%c%c%csystem(cmd);%c%c%c}%c%c}%c%creturn (0);%c}";
		filename = (char *)malloc(sizeof(char) * 10);
		cmd = (char *)malloc(sizeof(char) * 150);
		sprintf(filename, "Sully_%d.c", i - 1);
		fp = fopen(filename, "w");
		fprintf(fp, str, 10, 10, 34, 34, 10, 10, i - 1, 10, 10, 10, 10, 9, 10, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 10, 9, 9, 9, 34, str, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 34, 37, 34, 10, 9, 9, 34, 34, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 10, 9, 9, 9, 34, 37, 37, 37, 34, 10, 9, 9, 9, 10, 9, 9, 10, 9, 10, 9, 10);
		fclose(fp);
		if (i - 1 > 0)
		{
			sprintf(cmd, "clang -Wall -Wextra -Werror -o %s %s; ./%s", EXEC, filename, EXEC);
			system(cmd);
		}
	}
	return (0);
}