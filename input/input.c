#include "../kernel.h"
#include "input.h"

// tabla de registro de teclado qwerty

char scancode_to_ascii_qwerty[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,'a','s','d','f','g','h','j','k','l',';','\'','`',
    0,'\\','z','x','c','v','b','n','m',',','.','/',0,
    '*',0,' ',0
};

// agarrar un digito de entrada

char getc() {
  unsigned char scancode;
  unsigned char status;

  while(1) {
    status = inb(0x64);
    if(status & 1) {                                                                          if(status & 0x20) {
        inb(0x60);                                                                              continue;
      }

      scancode = inb(0x60);

      if(scancode == 0xE0) {
        while(!(inb(0x64) & 1));
        inb(0x60);
        continue;
      }

      if(scancode < 128) {
        if(scancode_to_ascii_qwerty[scancode])
          return scancode_to_ascii_qwerty[scancode];
      }
    }
  }
}

