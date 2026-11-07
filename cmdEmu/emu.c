#include "emu.h"
#include "../kernel.h"
#include "../input/input.h"
#include "../vga/vga.h"

void start() {
  char str[32];
  int crrPos = 0;

  logstr("Silx Kernel 26.5 By Christiam Jhabiel");
  logln();
  logstr("____");
  logln();
  logstr("            / . .\\");
  logln();
  logstr("MT          \\  ---<");
  logln();
  logstr("             \\  /");
  logln();
  logstr("   __________/ /");
  logln();
  logstr("-=:___________/");
  logln();
  logstr("kernel>>");
  while(1) {
    char c = getc();

    if (c == '\n') {
      logln();
      if(str[0] == 'h' && str[1] == 'e' && str[2] == 'l' && str[3] == 'p' && str[4] == '-' && str[5] == '-') {
        logstr("made by Christiam");
      } else {
        logstr("'");
        for(int i = 0;i<32;i++) logc(str[i]);
        logstr("' was no recognized");
      }
      crrPos = -1;
      for(int i = 0;i<32;i++) str[i] = '\0';
      logstr("kernel>>");
    } else if( c == '\b') {
      str[crrPos-1] == '\0';
      crrPos--;
    } else {
      str[crrPos] = c;
    }
    for(int i = 0;i<32;i++) logc(str[i]);
    crrPos++;
  }
}
