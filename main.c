#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "middle.h"







char* rgb;
static int rgbColors[3];



int* HexToInt(char *rgbHex);
int* HexToInt(char *rgbHex) {


	if (strncmp(rgbHex,"0x",2) == 0)
	{
		memmove(rgbHex, rgbHex + 2, strlen(rgbHex + 2) + 1);
	}
	if (strncmp(rgbHex,"#",1) == 0)
	{
		memmove(rgbHex, rgbHex + 1, strlen(rgbHex + 2) + 1);
	}


	char r[3] = {rgbHex[0],rgbHex[1],'\0'};
	char g[3] = {rgbHex[2],rgbHex[3],'\0'};
	char b[3] = {rgbHex[4],rgbHex[5],'\0'};


	rgbColors[0] = (int)strtol(r,NULL,16);
	rgbColors[1] = (int)strtol(g,NULL,16);
	rgbColors[2] = (int)strtol(b,NULL,16);

	return rgbColors;
}

char *CenterString(char *msg);
char *CenterString(char *msg)
{
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
	int row = w.ws_row;
	int col = w.ws_col;
	int centerText = col/2+strlen(msg)/2;
	printf("col:%d row:%d",col,row);


	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}
	printf("%*s%s",centerText,msg,CRESET);
	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}
	
	return msg;
}

int main(int argc,char *argv[]) {



	for (int i = 0;i < argc;i++)
	{
		if (!argv[1] 
		|| strcmp(argv[1],"--help") == 0 
		|| strcmp(argv[1],"help") == 0 
		|| strcmp(argv[1],"-h") == 0 )
		{
		
			printf("midchr: Middle Characters\n");

			printf(BWHT "USE:\n" CRESET);
			printf("\tmidchr \"Text\" [OPTION] \n");
			

			printf(BWHT "\nOPTIONS:" CRESET);
			
			printf("\n\t");
			printf("--rgb=HEX\tRGB Colors");

			printf("\n\t");
			printf("--green\t\tGreen Foreground");
			printf("\n\t");
			printf("--red\t\tRed Foreground");
			printf("\n\t");
			printf("--blue\t\tBlue Foreground");
			printf("\n\t");
			printf("--magenta\tMagenta Foreground");
			printf("\n\t");
			printf("--black\t\tBlack Foreground");
			printf("\n\t");
			printf("--yellow\tYellow Foreground");
			printf("\n\t");
			printf("--cyan\t\tCyna Foreground");
			printf("\n\t");
			printf("--white\t\tWhite Foreground");
			printf("\n");


			printf("\n\t");
			printf("-B\t\tBold Text");
			printf("\n\t");
			printf("-b\t\tBlink Text (doesn't work on some terminals)");
			printf("\n\t");
			printf("-i\t\tItalic Text ");
			printf("\n");

			return -1;
		}
		
		else if (strcmp(argv[i],"-B") == 0)
		{
			printf(BLD " ");
		}

		else if (strcmp(argv[i],"-b") == 0)
		{
			printf(BLN " ");
		}
		else if (strcmp(argv[i],"-i") == 0)
		{
			printf(ITC " ");
		}




		
		
		else if (strncmp(argv[i],"--rgb=",6) == 0)
		{
			rgb = argv[i] + strlen(argv[i]) - 6 ;

			int *rgbShColors = HexToInt(rgb);
			


			printf("\e[38;2;%d;%d;%dm",rgbShColors[0],
					rgbShColors[1],rgbShColors[2]);
			
		}

		else if (strcmp(argv[i],"--red") == 0)
		{
			printf(RED " ");
		}

		else if (strcmp(argv[i],"--blue") == 0)
		{
			printf(BLU " ");
		}

		else if (strcmp(argv[i],"--magenta") == 0)
		{
			printf(MAG " ");
		}

		else if (strcmp(argv[i],"--black") == 0)
		{
			printf(BLK " ");
		}

		else if (strcmp(argv[i],"--green") == 0)
		{
			printf(GRN " ");
		}

		else if (strcmp(argv[i],"--yellow") == 0)
		{
			printf(YEL " ");
		}
		else if (strcmp(argv[i],"--cyan") == 0)
		{
			printf(CYN " ");
		}
		else if (strcmp(argv[i],"--white") == 0)
		{
			printf(WHT " ");
		}

	}
	CenterString(argv[1]);




	return 0;
}
