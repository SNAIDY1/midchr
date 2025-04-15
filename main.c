#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <own/termcolor.h>

char *CenterString(char *msg);
char *CenterString(char *msg)
{
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
	int row = w.ws_row;
	int col = w.ws_col;
	int centerXText = col/2+strlen(msg)/2;


	//printf("lines: %d\ncolumns: %d\n",w.ws_row,w.ws_col);
	for (int i = 0;i < row/2+5;i++)
	{
		printf("\n");
	
	}
	printf("%*s",centerXText,msg);
	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}
	
	return msg;
}

int main(int argc,char *argv[]) {


	if (!argv[1] 
	|| strcmp(argv[1],"--help") == 0 
	|| strcmp(argv[1],"help") == 0 
	|| strcmp(argv[1],"-h") == 0 )
	{
	
		printf("midchr: Middle Characters\n");

		printf(BWHT "USE:\n" CRESET);
		printf("\tmidchr [OPTION] \"Arg\" \n");

		/*
		printf(BWHT "\nOPTIONS:" CRESET);
		printf("\n\t");
		printf("-fg=COLOR\tForeground Color\n");
		printf("\n\t");
		printf("-bg=COLOR\tBackground Color\n");
		*/
		return -1;
	}
	CenterString(argv[1]);


	return 0;
}
