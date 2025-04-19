#define RGBHEX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "middle.h"




static char *color;
int centerText;

// FUCK This Function
// I Was Fixing It For 2 Days
int* HexToIntRGB(char *rgbHex);
int* HexToIntRGB(char *rgbHex) {

	static int rgbColors[4];
	char rgbHexHandle[7];


	
	if (strncmp(rgbHex,"0x",2) == 0)
	{
		strncpy(rgbHexHandle,rgbHex+2,6);
	}
	else if (strncmp(rgbHex,"#",1) == 0)
	{
		strncpy(rgbHexHandle,rgbHex+1,6);
	}


	
	
	char r[3] = {rgbHexHandle[0],rgbHexHandle[1],'\0'};
	char g[3] = {rgbHexHandle[2],rgbHexHandle[3],'\0'};
	char b[3] = {rgbHexHandle[4],rgbHexHandle[5],'\0'};


	rgbColors[0] = (int)strtol(r,NULL,16);
	rgbColors[1] = (int)strtol(g,NULL,16);
	rgbColors[2] = (int)strtol(b,NULL,16);

	return rgbColors;
}




void RGB(char *hex)
{
	int *test = HexToIntRGB(hex);
	printf("\e[38;2;%d;%d;%dm",test[0],test[1],test[2]);
}


void Midchr(const char* msg) {
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
	int row = w.ws_row;
	int col = w.ws_col;
	int centerText = col/2+strlen(msg)/2;


	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}
	printf("%*s%s\n",centerText,msg,CRESET);
	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}
	
}
void MidchrY(const char* msg)
{
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
	int row = w.ws_row;
	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}
	printf("%s%s\n",msg,CRESET);
	for (int i = 0;i < row/2;i++)
	{
		printf("\n");
	
	}

}
void MidchrX(const char* msg)
{
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
	int col = w.ws_col;
	int centerText = col/2+strlen(msg)/2;
	printf("%*s%s\n",centerText,msg,CRESET);

}
