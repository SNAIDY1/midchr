# midchr
## About midchr
midchr Stands for middle character.<br/>
Its used for centering characters in unix shells

## Features
* RGB Colors Using Hexdecimal (#00ff00 OR 0x00ff00 OR 00ff00)
* Text Formatting Styles:
  + Italic
  + Bold
  + Blink
* Can Be Used In C Your Program

## How To Use midchr Program
Its very simple<br/>
to center text in the center of shell: <br/>
```sh
midchr "Hello World"
```

to use rgb hex colors:<br/>
```sh
midchr "Hello World" --rgb=#374f75 # Even "0x00ff00" And "00ff00 Allowed"
```


Pretty Simple!

## How To Use midchr Library

To include midchr libary:
```C
#include "middle.h"
```
define RGBHEX To Use rgb hex colors:
```C
#define RGBHEX
```

Functions and what they do:
| Function  | what it do |
| ------------- | ------------- |
| void Midchr(const char* msg)  | Center Text In X And Y  |
| void MidchrY(const char* msg) | Center Text In Y        |
| void MidchrX(const char* msg) | Center Text In X        |
| void RGB(char *hex)           | Coloring Text (define RGBHEX to use it) |

## Example
```C
#define RGBHEX
include "middle.h"

int main() {

    RGB("0xff0000");
    MidchrX("Hello Middle Character!!");

}
```

