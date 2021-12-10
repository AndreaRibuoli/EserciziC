/*

   Autore:                  Andrea Ribuoli (2021)
   nell'ambito di:      FONDAMENTI DI PROGRAMMAZIONE
                     ITS "Magento & e-commerce software"
                     
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "converti_api.h"
static union { char c[__SIZEOF_LONG__]; unsigned long a_long; } test;
#define ENDIANNESS ((char) test.a_long)

void inverti(char *s);

int converti_api(char *CP, char *utf8) {
    char *end;
    char str[__SIZEOF_LONG__ + 1];
    unsigned long *b  = (unsigned long *)(str);
    unsigned long i;
    test.c[0] = 'l';
    test.c[__SIZEOF_LONG__ - 1] = 'b';
    memset(str, '\0', sizeof(str));
    i = strtol(CP, &end, 16);
    if (i <= 127) {
      *b = i;  
      if (ENDIANNESS == 'l') inverti(str);
      sprintf(utf8, "%s", &(str[sizeof(long)-1]));
    } else if (i <= 2047) {
      *b = (((i & 0x07C0) << 2) | (i & 0x003F)) | 0xC080;  
      if (ENDIANNESS == 'l') inverti(str);
      sprintf(utf8, "%s", &(str[sizeof(long)-2]));
    } else if (i <= 65535) {
      *b = (((i & 0xF000) << 4) | ((i & 0x0FC0) << 2) | (i & 0x003F)) | 0xE08080;  
      if (ENDIANNESS == 'l') inverti(str);
      sprintf(utf8, "%s", &(str[sizeof(long)-3]));
    } else {
      *b = (((i & 0x03F000) << 4) | ((i & 0x0FC0) << 2) | (i & 0x003F)) | 0xF0808080;  
      if (ENDIANNESS == 'l') inverti(str);
      sprintf(utf8, "%s", &(str[sizeof(long)-4]));
    }
    return 0; 
}

void inverti(char *s) {
  char p;
  for (int j=0; j< (sizeof(long) / 2); j++) {
    p = s[j];
    s[j] = s[sizeof(long)-1-j];
    s[sizeof(long)-1-j] = p;
  }
}
