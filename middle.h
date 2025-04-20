#ifndef MIDDLE_H
#define MIDDLE_H

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define CRESET "\e[0m"

#define BLD "\e[1m"
#define ITC "\e[3m 
#define BLN "\e[5m"



void Midchr(const char* msg);
void MidchrY(const char* msg);
void MidchrX(const char* msg);

#ifdef RGBHEX
void RGB(char *hex);
#endif

#endif
