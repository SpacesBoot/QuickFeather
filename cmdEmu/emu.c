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
      logstr("❯ ");
      for(int i = 0; i < 32; i++) logc(str[i]);
      logln();
      if(str[0] == 'h' && str[1] == 'e' && str[2] == 'l' && str[3] == 'p' && str[4] == '-' && str[5] == '-') {
        logstr("made by Christiam");
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
