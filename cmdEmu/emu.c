#include "emu.h"
#include "../kernel.h"
#include "../input/input.h"
#include "../vga/vga.h"

void start() {
  char str[32];
  int crrPos = 0;

  logstr("QuickFeather 26.7 Kernel");
  logln();
  while(1) {
    char c = getc();

    if (c == '\n') {
        logstr("> ");
        for(int i = 0; i < 32; i++) logc(str[i]);
        logln();
        if(str[0] == '-' && str[1] == '-' && str[2] == 'h' && str[3] == 'e' && str[4] == 'l' && str[5] == 'p') {
          logstr("--help = help with basic commands");
          logln();
          logstr("--version = kernel version, system, etc.");
          logln();
        } else if (str[0] == '-' && str[1] == '-' && str[2] == 'v' && str[3] == 'e' && str[4] == 'r' && str[5] == 's' && str[6] == 'i' && str[7] == 'o' && str[8] == 'n'){
          logstr("kernel: 26.7 3:15");
          logln();
        } else {
          logstr("'");
          for(int i = 0;i<32;i++) logc(str[i]);
          logstr("' was no recognized");
        }
        logln();
        crrPos = -1;
        for(int i = 0;i<32;i++) str[i] = '\0';
      } else if( c == '\b') {
        str[crrPos-1] == '\0';
        crrPos--;
      } else {
        str[crrPos] = c;
      }
    crrPos++;
  }
}
