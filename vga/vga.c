#include "vga.h"

unsigned short* vga = (unsigned short*)0xB8000;
int cursor;

void logln() {
  cursor = (cursor / 80 + 1) * 80;
}

void logstr(const char * str) {
  for( int i = 0; str[i] != '\0'; i++ ) {
    vga[cursor] = (unsigned short)0x0F00|str[i];
    cursor++;
  }
}

void logc(const char c) {
  vga[cursor] = (unsigned  short)0x0F00|c;
  cursor++;
}
