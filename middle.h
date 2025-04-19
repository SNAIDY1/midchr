#ifndef MIDDLE_H
#define MIDDLE_H

// Colors
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

// Reset Colors and Text Formatting To Default
#define CRESET "\e[0m"

// Text Formatting Styles
#define BLD "\e[1m" // Bold
#define ITC "\e[3m" // Italic
#define BLN "\e[5m" // Blink



// Text Centering Functions
void Midchr(const char* msg);  // Center Text In X And Y
void MidchrY(const char* msg); // Center Text In Y
void MidchrX(const char* msg); // Center Text In X

#ifdef RGBHEX
void RGB(char *hex);
#endif

#endif
